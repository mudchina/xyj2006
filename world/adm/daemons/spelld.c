// spell_d.c.
// mon 12/6/98
//lestat 2001 9重新修正
//修正后综述,法术命中率比较高,毕竟这是法术世界,同时反震几率低,反震伤害小
//命中率取决于自身的道行,法术等级
//伤害则完全看自身法力修为和战斗中的enchant大小
//基本上不太可能溢出,法术等级修为的提升,应该是一个自我完善的过程
//施展法术可能遭受的反震伤害则与自身的法术修为有关,修为越高,伤害越小
//不断的提高道行,提高法术等级,则可以增加实战中法术的命中率
#include <ansi.h>

/* table for 法术相克 
   for example,
	"dao": ({"yaofa","dengxian-dafa"}),
   means, dao can 克制 yaofa and dengxian-dafa.
   */
//大唐14个门派法术相克图
mapping table=([
	"baguazhou": ({"pansi-dafa"}),
	"buddhism": ({"pingtian-dafa"}),
	"dao": ({"yaofa"}),
	"taiyi": ({"moonshentong"}),
	"taoism": ({"dengxian-dafa"}),
	"mysticism": ({"yuxu-spells"}),
	"yuxu-spells": ({"taoism"}),
	"dengxian-dafa": ({"dao"}),
	"pingtian-dafa": ({"mysticism"}),
	"pansi-dafa": ({"buddhism"}),
	"yaofa": ({"gouhunshu"}),
	"gouhunshu": ({"taiyi"}),
	"moonshentong": ({"seashentong"}),
	"seashentong": ({"baguazhou"}),
	]);

/* determine whether two 法术 are 相克制
   if spell1 克制 spell2, then return = 1.
   if spell2 克制 spell1, then return = -1.
   otherwise, return 0.
   */
int skill_xiangke(string spell1, string spell2)
{
    int neutral=0;
    int result;    
    if(undefinedp(table[spell1]) ||
	    undefinedp(table[spell2])) return neutral;
    if(member_array(spell1, table[spell2])>-1) {
	// spell2 can 克制 spell1.
	result=-1;
    } else if(member_array(spell2, table[spell1])>-1) {
	// spell1 can 克制 spell2.
	result=1;
    } else {
	result=neutral;
    }    
    return result;
}

/* determine whether two players' 法术 are 相克制
   only effective between two players,
   or a NPC against a player,
   can't a player take advantage of a npc.
   if obj1 克制 obj2, then return = 1.
   if obj2 克制 obj1, then return = -1.
   otherwise, return 0.
   */
int check_xiangke(object obj1, object obj2)
{
    int neutral=0;
    int result;
    string skill1, skill2;    
    skill1=obj1->query_skill_mapped("spells");
    skill2=obj2->query_skill_mapped("spells");
    // need at least 20 level of special spells.
    if((int)obj1->query_skill(skill1,1)<20) return neutral;
    if((int)obj2->query_skill(skill2,1)<20) return neutral;
    result=skill_xiangke(skill1, skill2);
    if(!userp(obj1)) { // obj1 is npc
	if(userp(obj2) && result== -1)
	    result=0;
    } else if(!userp(obj2)) { // obj2 is npc, obj1 is player
	if(result==1)
	    result=0;
    }
    return result;
}

int attacking_cast_success(object attacker, object target, int success_adj)
{
	int ap, dp, success;
	int xk; 
	ap = attacker->query_skill("spells");
        ap = ( ap * ap / 1000 * ap  ); //年做单位进行比较判断.
	//道行超过5000年,提高命中.
	ap = ap*(1+attacker->query("daoxing")/5000000);//5万年道行导致ap*11
	ap = ap+attacker->query("daoxing")/1000;
        dp = target->query("daoxing");
	success = 0;
	if ( success_adj < 20 ) success_adj = 20;
	else if( success_adj > 500 ) success_adj = 500;
	ap = ap/100*success_adj;
	xk=check_xiangke(attacker, target);
	if(xk==1) {
	    dp=dp/2;
	} else if(xk==-1) {
	    ap=ap/2;
	}
	if( random(100)>dp/(ap+dp)*100 ) success = 1;
	return success;//命中仅仅取决于自己的法术修为和道行修为,武学和道行完全分离.
}

int attacking_cast_damage(object attacker, object target, int damage_adj)
{
	int a_fali, d_fali, damage, damage_bonus;
	int xk;
	if( damage_adj < 50 ) damage_adj = 50;
        else if( damage_adj > 200 ) damage_adj = 200;
	a_fali = attacker->query("mana");
	if( a_fali > 2*attacker->query("max_mana") ) a_fali = 2*attacker->query("max_mana");
	d_fali = target->query("mana");
	if( d_fali > 2*target->query("max_mana") ) d_fali = 2*target->query("max_mana");
	a_fali=a_fali/40+random(attacker->query("eff_sen") / 20);
	d_fali=d_fali/40+random(target->query("eff_sen") / 20);
        a_fali+=(damage_adj/100)*(attacker->query("mana_factor"));
        d_fali+=(damage_adj/100)*random(target->query("mana_factor"));
        //由于高段位以后升级缓慢,伤害必须封顶
        if( a_fali > d_fali )
        {
            damage=a_fali-d_fali;
            damage+= (damage_adj/100)*(attacker->query("mana_factor"));
            damage = damage*damage_adj/100;
            damage_bonus = (int)attacker->query_skill("spells")/200;
            if(damage_bonus > 3) damage_bonus = 3;
            damage += damage*damage_bonus;
            if( damage > 3000 ) damage = 3000;//伤害封顶
        }
        else if( d_fali > a_fali ) 
        {   
            if( d_fali > 400 ) d_fali = 400;
            damage = d_fali;//鼓励使用法术,反震伤害封顶
            damage = damage - target->query("mana_factor"); 
            damage = damage*damage_adj/100;
            damage_bonus = (int)attacker->query_skill("spells")/100;
            if(damage_bonus < 1) damage_bonus = 1;
            if(damage_bonus > 10) damage_bonus = 10;
            damage += damage/damage_bonus;//自身修为的高低在这里起到作用
         }
        else
        damage=a_fali-d_fali;        
	return damage;
}

//weiqi 981206
//this function can be called when want apply a damage to a victim while allow
//the victim use his/her self-made fabao to defense.
void apply_damage(object winner, object victim, 
	int damage, string damage_type, string msg_hit)
{
	int i, temp, type, damage_qi, damage_shen,adjust,success;
	object *inv;
	int def_count = 0;
	string *msg_fabao = ({
		"只见$N的$n霞光一闪！\n",
		"只见$N的$n霞光再闪！\n",
		"只见$N的$n霞光又一闪！\n",
		"只见$N的$n霞光再一闪！\n"
	});
	if( victim->query_temp("anti_magic") )
	{
		adjust=(int)victim->query_temp("anti_magic");

		if( (int)victim->query("mana") < adjust)
			success=0;
		else
			success=1;

		if( success )
		{
			victim->add("mana", -adjust);
			damage_qi=damage_qi - adjust/2;
			damage_shen=damage_shen - adjust/2;
			if ( damage_qi > 0 || damage_shen > 0 )
				message_vision("\n只见$N身后幻出千朵白莲，挡住了$n的攻势。\n", victim, winner);
			else
				message_vision("\n只见$N身后幻出千朵白莲，将$n的攻势尽数化解。\n", victim, winner);
		}
	}


	if( damage <= 0 ) return;

	if(damage_type == "qi" || damage_type == "kee") 
	{
		damage_qi = damage;
		damage_shen = 0;
		type = 0;
	}
	else if(damage_type == "shen" || damage_type == "sen") 
	{
		damage_qi = 0;
		damage_shen = damage;
		type = 1;
	}
	else 
	{
		damage_qi = damage;
		damage_shen = damage;
		type = 2;
	}

	//check if the victim equipped defense fabao...
	inv = all_inventory(victim);
	for( i=0; i<sizeof(inv); i++)
	{
		if( !inv[i]->query("series_no") ||  !inv[i]->query("fabao") || !inv[i]->query("equipped") )
			continue;//not a equipped fabao.

		if( (type == 0) || (type == 2) ) //check if can reduce damage_qi.
		{
			temp = inv[i]->protect_qi(damage_qi);
			//temp is the damage left after fabao takes effect.

			if( temp < damage_qi ) //means fabao useful.
			{
				damage_qi = temp;
				message_vision(msg_fabao[def_count], victim, inv[i]);
				def_count++;	
			}
		}

		if( (type == 1) || (type == 2) ) //check if can reduce damage_shen.
		{
			temp = inv[i]->protect_shen(damage_shen);
			//temp is the damage left after fabao takes effect.

			if( temp < damage_shen ) //means fabao useful.
			{
				damage_shen = temp;
				message_vision(msg_fabao[def_count], victim, inv[i]);
				def_count++;	
			}
		}
	}//end of for i=0 loop.

	//finally we can make damage to the victim...
	if( damage_qi > 0 || damage_shen > 0 )
		//produce the hit message...
		message_vision(msg_hit, winner, victim);
	else
		//the fabao saved the target...
		message_vision("结果$N的攻击完全被$n的法宝挡住！
\n", winner, victim);

	if( damage_qi > 0 )
	{
                victim->receive_damage("kee", damage_qi*3/5, winner);
		victim->receive_wound("kee", damage_qi/2, winner);	
		COMBAT_D->report_status(victim);	
	}
	if( damage_shen > 0 )
	{
                victim->receive_damage("sen", damage_shen*3/5, winner);
		victim->receive_wound("sen", damage_shen/2, winner);	
		COMBAT_D->report_sen_status(victim);
	}

	return;
}

/*
weiqi 981206
attacking-cast...called from spells function.
a typical call would be:

	SPELL_D->attacking_cast(
		me, 
			//attacker 
		target, 
			//target
		success_adj, 	
			//success adjustment
		damage_adj, 	
			//damage adjustment
		"both", 		
			//damage type: could be "qi"/"kee", "shen"/"sen", ...default "both"
		HIC "$N几个指头迅速捻动，突然张嘴一喷！红橙黄三道火焰呼！地一声向$n卷去！\n" NOR,
			//initial message
		HIC "结果$n被烧得焦头烂额！\n" NOR, 
			//success message
		HIC "但是$n轻轻一跳就躲了开来。\n" NOR, 
			//fail message
		HIC "但是火焰被$n以法力一逼，反向$N回卷而去！\n" NOR, 
			//backfire initial message
		HIC "结果太乙真火反噬，$n被烧得焦头烂额！\n" NOR
			//backfire hit message. note here $N and $n!!!
	);
*/
void attacking_cast(
	object attacker, 
	object target, 
	int success_adj, 
	int damage_adj, //default value is 100 for this 2 parameters.
	string damage_type, //must be "shen"/"sen", "qi"/"kee" or "both"(default)
	string msg_init, 
	string msg_success, 
	string msg_fail, 
	string msg_backfire_init,
	string msg_backfire_success)
{
	int damage;

	//first, show the initial message...
	message_vision( msg_init, attacker, target );
	
	//calculate if the casting can happen...
	if( attacking_cast_success(attacker, target, success_adj) == 0 )
	{
		message_vision( msg_fail, attacker, target );
		//let the target kill attacker.
		target->kill_ob(attacker);	
		return;
	}
	
	damage = attacking_cast_damage(attacker, target, damage_adj);

	if( damage > 0 ) //attacker hit target
		apply_damage(attacker, target, damage, damage_type, msg_success);
	
	else if( damage < 0 ) //backfire
	{
		message_vision(msg_backfire_init, attacker, target);
		apply_damage(target, attacker, -damage, damage_type, msg_backfire_success);
	}

	else //damge=0
		message_vision(HIB "结果正好被$N以法力逼住，谁也没有吃亏。\n" NOR, target);

	//let the target kill attacker.
	target->kill_ob(attacker);

	return;
}



