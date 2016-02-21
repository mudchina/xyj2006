// fabao.c

#include <weapon.h>
#include <armor.h>
#include <ansi.h>

inherit EQUIP;
inherit F_SAVE;
inherit F_BACKUP;

void create()
{
	seteuid(0);	
	set_name("自制法宝物件", ({ "fabao object", "fabao", "object" }) );
	setup();
}

void init()
{
	add_action("do_charge", "improve");
	add_action("do_charge", "charge");
	add_action("do_charge", "recharge");
}

void reset()
{
	if( !environment() ||  //mon 2/4/98
		query("owner_id") != getuid(environment()) )  
	{
		destruct(this_object());
		return;
	}
}

// This is used by F_SAVE to determine the filename to save our data.
string query_save_file()
{
	string id, series;

	id = query("owner_id");
	series = query("series_no");
	if( !id || !series) return 0;

	return sprintf(DATA_DIR "fabao/%c/%s-%s", id[0], id, series);
}

int save()
{
	//is this needed?...
	if( query("equipped") )   
	{
		write("必须放下法宝才能储存。\n");
		return 0;
	}
	return ::save();
}

void setup()
{
	::setup();
}

int query_unique()  { return 1; }

string status_bar(int max, int current, string color)
{//note: the color string must be things like HIB, HIW, ...etc.
	int i;
	string status = color;

	if( max <=0 ) return " ";

	if( max > 25 ) max = 25;
	if( current > max ) current = max;

	for(i=1; i<=max; i++)
	{
		if( i <= current ) status += "■";
		else status += "□";
	}
   
	status += NOR;

	return status;   
}

string show_status()
{
	string status = (string)query("name")+"法宝状态：\n";
	
	if( query("series_no") == "1" ) //weapon
	{
		status += " <气血伤害力> " + status_bar(query("fabao/max_attack_qi"), query_temp("fabao/attack_qi"), RED) + "\n";
		status += " <精神伤害力> " + status_bar(query("fabao/max_attack_shen"), query_temp("fabao/attack_shen"), BLU) + "\n";
	}

	else //armor
	{
		status += " <气血保护力> " + status_bar(query("fabao/max_defense_qi"), query_temp("fabao/defense_qi"), RED) + "\n";
		status += " <精神保护力> " + status_bar(query("fabao/max_defense_shen"), query_temp("fabao/defense_shen"), BLU) + "\n";
		status += " <法宝收取力> " + status_bar(query("fabao/max_defense_shou"), query_temp("fabao/defense_shou"), HIY) + "\n";	
	}

	return status;
}

//to actually use the fabao as a powerful tool, players need to charge it.
//each time let the player fill one square.
int do_charge(string arg)
{
	object me= this_player();
	object fabao_ob= this_object();
	int cost = 100;//now fix cost as 100, both fali and neili
        int delay_factor = 20;//actually delay is cost/delay_factor...in unit of second.
	
	if( me->is_busy()
	|| me->is_fighting()
	|| me->query_temp("pending/exercising"))
		return notify_fail("你正忙着呢．．．\n");
        
	if( environment(me)->query("no_fight")
	|| environment(me)->query("no_magic") )
		return notify_fail("这里不是修炼法宝的地方。\n");

	if( !arg || !fabao_ob->id(arg) ) return notify_fail("你想修炼什么法宝？\n");
	
	if( (int)me->query("mana") < 3*cost ) //maybe used to charge 3 parameters.
		return notify_fail("你目前的法力太低，不能修炼法宝。\n");

	if( (int)me->query("force") < 3*cost ) //maybe used to charge 3 parameters.
		return notify_fail("你目前的内力太低，不能修炼法宝。\n");

	if( query("series_no")=="1" )//weapon
	{
		if( query_temp("fabao/attack_qi") >= query("fabao/max_attack_qi") )
			write(query("name")+"的气血伤害力已在最佳状态。\n");
		else 
		{
			me->add("force", -cost);
			me->add("mana", -cost);
			message_vision("$N口中念念有词，以法力将自己的内力缓缓地注入$n之中。\n", me, fabao_ob);
			me->start_busy(cost/delay_factor);
			call_out("charged", cost/delay_factor, me, "attack_qi");
		}

		if( query_temp("fabao/attack_shen") >= query("fabao/max_attack_shen") )
			write(query("name")+"的精神伤害力已在最佳状态。\n");
		else 
		{
			me->add("force", -cost);
			me->add("mana", -cost);
			message_vision("$N口中念念有词，以内力将自己的法力缓缓地注入$n之中。\n", me, fabao_ob);
			me->start_busy(cost/delay_factor);
			call_out("charged", cost/delay_factor, me, "attack_shen");
		}

		return 1;
	}

	else //armor
	{
		if( query_temp("fabao/defense_qi") >= query("fabao/max_defense_qi") )
			write(query("name")+"的气血保护力已在最佳状态。\n");
		else 
		{
			me->add("force", -cost);
			me->add("mana", -cost);
			message_vision("$N口中念念有词，以法力将自己的内力缓缓地注入$n之中。\n", me, fabao_ob);
			me->start_busy(cost/delay_factor);
			call_out("charged", cost/delay_factor, me, "defense_qi");
		}

		if( query_temp("fabao/defense_shen") >= query("fabao/max_defense_shen") )
			write(query("name")+"的精神保护力已在最佳状态。\n");
		else 
		{
			me->add("force", -cost);
			me->add("mana", -cost);
			message_vision("$N口中念念有词，以内力将自己的法力缓缓地注入$n之中。\n", me, fabao_ob);
			me->start_busy(cost/delay_factor);
			call_out("charged", cost/delay_factor, me, "defense_shen");
		}

		if( query_temp("fabao/defense_shou") >= query("fabao/max_defense_shou") )
			write(query("name")+"的法宝收取力已在最佳状态。\n");
		else 
		{
			me->add("force", -cost);
			me->add("mana", -cost);
			message_vision("$N口中念念有词，将自己的法力和内力交汇，缓缓地注入$n之中。\n", me, fabao_ob);
			me->start_busy(cost/delay_factor);
			call_out("charged", cost/delay_factor, me, "defense_shou");
		}

		return 1;
	}

}

void charged(object me, string type)
{
	string property, max;
	property = "fabao/"+type;
	max = "fabao/max_"+type;

	if( query_temp(property) >= query(max) ) return;
	add_temp(property, 1);
	//save();//do not save...use temp now.
	message_vision("\n只见$n突然放出五彩霞光，$N面露喜色，长长地吐了一口气。\n", me, this_object());
	return;
}

//this function calculate, when a damage comes, how the fabao reduce it.
//the returned value is the damage left.
int protect_qi(int damage)
{
	int i, square;

	int def_unit = 20;
	//this is the damage each square can reduce.
	//currently it is fix...
	//can also use query("fabao/def_unit") if set it somewhere, not implemented yet.

	if( damage <= 0 ) return 0;

	square = query_temp("fabao/defense_qi");
	if( square == 0 ) return damage;

	i = damage/def_unit;

	if( i >= square )
	{//more damage
		set_temp("fabao/defense_qi",  0);
		//save();
		return damage - square*def_unit;
	}
	else
	{//more protect potential.
		set_temp("fabao/defense_qi", square-i);
		//save();
		return 0;
	}
}

int protect_shen(int damage)
{
	int i, square;

	int def_unit = 20;
	//this is the damage each square can reduce.
	//currently it is fix...
	//can also use query("fabao/def_unit") if set it somewhere, not implemented yet.

	if( damage <= 0 ) return 0;

	square = query_temp("fabao/defense_shen");
	if( square == 0 ) return damage;

	i = damage/def_unit;

	if( i >= square )
	{//more damage
		set_temp("fabao/defense_shen",  0);
		//save();
		return damage - square*def_unit;
	}
	else
	{//more protect potential.
		set_temp("fabao/defense_shen", square-i);
                //save();
		return 0;
	}
}

int ji(string target_id)
{
        int a_dx, a_exp, a_fali, a_enchant;
        int d_dx, d_exp, d_fali, d_enchant;
        int d_fabao_power, a_fabao_power;
        int damage;
        string hit_msg;
        int i, j;
        
        object fabao = this_object();
        object attacker = this_player();
        string fabao_name=fabao->query("name");
        object where=environment(attacker);
        object target;
        object *inv;
        object d_fabao1, d_fabao2;

        if (!target_id)
                return notify_fail("你想对谁祭"+fabao_name+"？\n");

        target=present(target_id, environment(attacker));
        if( !target )
                return notify_fail("你的攻击目标不在这里。\n");

        if( attacker->is_busy() )
                return notify_fail("你正忙着呢，无法祭出"+fabao_name+"。\n");
        if( where->query("no_magic") || where->query("no_fight") )
                return notify_fail("这里不能祭"+fabao_name+"。\n");

        if( (int)attacker->query("mana") < 500 )
                return notify_fail("你的法力不能控制"+fabao_name+"。\n");
        if( (int)attacker->query("sen") < 200 )
                return notify_fail("你现在神智不清，很难驾驭"+fabao_name+"。\n");

        if( !fabao->query("equipped") )
                return notify_fail(fabao_name+"还没装备起来。\n");

        message_vision(HIC"\n$N抖足精神，大喝一声“看法宝！”，只见$n「呼」地一下飞到半空，\n"NOR, attacker, fabao);
        message_vision(HIC"霎那间天色一变，风声大作！$n带出一道低啸向$N凌空击来！\n\n"NOR,  target, fabao);

        //start kill...
        target->kill_ob(attacker);


        attacker->add("mana", -300);
        attacker->add("sen", -100);
        attacker->start_busy(3+random(3));


//1st, daoxing vs. daoxing, if target dx enough, can prevent anything from happening.

//2nd, combat_exp vs. daoxing, if target exp enough, can 躲闪.

//3rd, fali vs. fali, if victim fali enough, can try use his/her defense fabao to 接收.
//here, damage to fabao's power may happen...

//4th, to this point, a successful hit happens, consider damage now. 
//damage is determined by attacker and target's enchant and attacking fabao's power.

        a_dx = (int)attacker->query("daoxing");
        a_exp = (int)attacker->query("combat_exp"); //this parameter no use now.
        a_fali = (int)attacker->query("mana");
        a_enchant = (int)attacker->query("mana_factor");

        d_dx = (int)target->query("daoxing");
        d_exp = (int)target->query("combat_exp");
        d_fali = (int)target->query("mana");
        d_enchant = (int)target->query("mana_factor");

        //stage 1, attacker's dx vs. target's dx
        if( d_dx*100/(a_dx+d_dx) > random(100) )
        {
                //message_vision(HIW"\n结果$N轻轻一挥手：米粒之珠，也放光华？\n"NOR, attacker);   
                message_vision(HIW"\n结果$N轻一挥手，嘿嘿笑了几声：想跟我斗？再去修个三五百年吧！\n"NOR, target);   
                message_vision(HIW"\n只见$n几个翻滚，又回到了$N的手中。\n"NOR, attacker, fabao);    
                return 1;    
        }

        //stage 2, attacker's dx vs. target's exp
        //note here, 1/3 exp can be considered as effective dx.
        if( (d_exp/3)*100/(a_dx+d_exp/3) > random(100) )
        {
                message_vision(HIC"\n结果$N身形急闪，躲过了$n的攻势。\n"NOR, target, fabao);
                return 1;
        }
        
        //stage 3, attacker's fali vs. target's fali
        //if target has a higher fali, he/she may want to try 收取对方法宝。
        //btw, this is determined by his/her defense fabao's power, hoho.
        if( d_fali*100/(a_fali+d_fali) > random(100) )
        {
                d_fabao_power = 0;
                j = 0;
                a_fabao_power = fabao->query("fabao/max_attack_qi")+fabao->query("fabao/max_attack_shen");
                //note here, 2 defense fabaos->2 max_defense_shou parameters
                //compare with 1 attack fabao->max_attack_qi+max_attack_shen.

                //check if the victim equipped defense fabao...
	        inv = all_inventory(target);
                for( i=0; i<sizeof(inv); i++)
	        {
                        if( !inv[i]->query("series_no") 
                                ||  !inv[i]->query("fabao") 
                                || !inv[i]->query("equipped") 
                                || inv[i]->query("series_no") == "1" )
			        continue;//not a equipped defense fabao.

                        d_fabao_power += inv[i]->query("fabao/max_defense_shou");  
                        j = j+1;
                        if( j==1 ) d_fabao1 = inv[i];
                        else if ( j== 2 ) d_fabao2 = inv[i];                  
                }

                if( d_fabao_power > 0 )
                {
                        message_vision(HIC"$N哼！了一声：米粒之珠，也放光华？看我的法宝！\n"NOR, target);
                        if( d_fabao1 ) 
                                message_vision(HIW"只见霞光一闪，$N的$n已跟"+fabao_name+"斗在一起！\n"NOR, target, d_fabao1);
                        if( d_fabao2 ) 
                                message_vision(HIW"只见霞光一闪，$N的$n已跟"+fabao_name+"斗在一起！\n"NOR, target, d_fabao2);
                        
                        if( a_fabao_power > d_fabao_power )//possible to damage defense fabao...
                        {
                                if( random( a_fabao_power - d_fabao_power ) > 3 ) 
                                {
                                        if( d_fabao2 )
                                        {
                                                if( d_fabao2->query("fabao/max_defense_qi") > 1 && random(2) == 0 )
                                                        d_fabao2->add("fabao/max_defense_qi", -1);
                                                if( d_fabao2->query("fabao/max_defense_shen") > 1 && random(2) == 0 )
                                                        d_fabao2->add("fabao/max_defense_shen", -1);                                                
                                                if( d_fabao1->query("fabao/max_defense_shou") > 1 && random(2) == 0 )
                                                        d_fabao2->add("fabao/max_defense_shou", -1);

                                                message_vision(HIC"结果血光大盛，$N发出一声哀鸣退了下来。\n"NOR, d_fabao2);
                                                if( d_fabao2->unequip() ) d_fabao2->save(); 
                                        }
                                        else if( d_fabao1 )
                                        {
                                                if( d_fabao1->query("fabao/max_defense_qi") > 1 && random(2) == 0 )
                                                        d_fabao1->add("fabao/max_defense_qi", -1);
                                                if( d_fabao1->query("fabao/max_defense_shen") > 1 && random(2) == 0 )
                                                        d_fabao1->add("fabao/max_defense_shen", -1);                                                
                                                if( d_fabao1->query("fabao/max_defense_shou") > 1 && random(2) == 0 )
                                                        d_fabao1->add("fabao/max_defense_shou", -1);

                                                message_vision(HIC"结果血光大盛，$N发出一声哀鸣退了下来。\n"NOR, d_fabao1);
                                                if( d_fabao1->unequip() ) d_fabao1->save(); 
                                        }   
                                         
                                        return 1;
                                }
                        }
                        else if( d_fabao_power > a_fabao_power )//possible to damage attack fabao
                        {
                                if( random( d_fabao_power - a_fabao_power ) > 3 ) 
                                {
                                        if( fabao->query("fabao/max_attack_qi") > 1 )
                                                fabao->add("fabao/max_attack_qi", -1);
                                        if( fabao->query("fabao/max_attack_shen") > 1 )
                                                fabao->add("fabao/max_attack_shen", -1);        
                         
                                        message_vision(HIC"结果血光大盛，$n发出一声哀鸣，居然被$N收了过去！\n"NOR, target, fabao);  
                                        if( fabao->unequip() ) fabao->save();//here save may cause bug?...

                                        fabao->move(target); 
                                        return 1;
                                }
                        }
                
                        message_vision(HIC"结果双方的法宝斗了个旗鼓相当，只好各自收回。\n"NOR, fabao);   
                        return 1;     
                }
        }

        //stage 4, finally, the fabao results in a hit to the target...
        //compare target's enchant + defense fabao with attacker's attacking fabao + enchat
        hit_msg = HIC "结果$n被打了个正着！\n" NOR;
        if( fabao->query_temp("fabao/attack_qi") > fabao->query_temp("fabao/attack_shen") )
        {//attack qi
                damage = fabao->query_temp("fabao/attack_qi")*attacker->query_spi() + a_enchant - (d_enchant/2+random(d_enchant/2));
                fabao->set_temp("fabao/attack_qi", 0);
                if( damage > 0 ) 
                {
                        SPELL_D->apply_damage(attacker, target, damage, "qi", hit_msg);
                        return 1;
                }
        }
        else if( fabao->query_temp("fabao/attack_qi") < fabao->query_temp("fabao/attack_shen") )
        {//attack shen
                damage = fabao->query_temp("fabao/attack_shen")*30 + a_enchant - (d_enchant/2+random(d_enchant/2));
                fabao->set_temp("fabao/attack_shen", 0);
                if( damage > 0 ) 
                {
                        SPELL_D->apply_damage(attacker, target, damage, "shen", hit_msg);
                        return 1;
                }
        }
        else
        {//both qi and shen
                damage = fabao->query_temp("fabao/attack_shen")*30 + a_enchant - (d_enchant/2+random(d_enchant/2));
                fabao->set_temp("fabao/attack_qi", 0);
                fabao->set_temp("fabao/attack_shen", 0);
                if( damage > 0 ) 
                {
                        SPELL_D->apply_damage(attacker, target, damage, "both", hit_msg);
                        return 1;
                }                
        }

        message_vision(HIC"结果$N硬受$n一记，却是毫发无伤！\n"NOR, target, fabao); 

        return 1;
}
