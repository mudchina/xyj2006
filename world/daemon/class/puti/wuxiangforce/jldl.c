// jldl.c
//write by yesi


#include <ansi.h>
#include <combat.h>

inherit F_CLEAN_UP;

void remove_effect(object me);
void check_mapped(object me);
string jldl_result(object me, object victim, int mod_val, int force_adj, mapping action);

int exert(object me, object target)
{
        int skill;


        skill = me->query_skill("wuxiangforce",1);

	if( skill > 250 ) skill=250;
	

        if( target != me ) 
		return notify_fail("你只能用借力打力提升自己的防御力。\n");

        if(time()-(int)me->query_temp("jldl_end") < 10) return notify_fail("你现在真气不纯。\n");
        
        if( (int)me->query("force") < skill*2 )     
		return notify_fail("你的内力不够。\n");
		
        if(me->query("family/family_name") != "方寸山三星洞")
                return notify_fail("[借力打力]是方寸山三星洞不传之密！\n");           
        
        
        if( me->query_temp("jldl") ) 
	{remove_effect(me);return 1;}

        me->add("force", -skill);
        message_vision(HIG "$N把小无相功在体内运行一周，只觉内力运行随心所欲无不如意！\n" NOR, me);
        me->set_temp("jldl", 1);
        me->set_temp("jldl_time",skill);
        call_out("check_mapped", 1, me);
        
        return 1;
}


void check_mapped(object me)
{
	if(!me) return;                
	if( me->query_skill_mapped("force") != "wuxiangforce" ) 
	remove_effect(me);
	else if(me->query_temp("jldl_time")<1)
	remove_effect(me);			
	else {  me->add_temp("jldl_time",-1);
		call_out("check_mapped", 1, me);
	     }
}


void remove_effect(object me)
{
        if(!me) return;
        remove_call_out("check_mapped");
        me->delete_temp("jldl");
        me->set_temp("jldl_end", time() );
	tell_object(me, "你的借力打力运行一周天完毕，将内力收回丹田。\n");
}


string jldl_result(object me, object victim, int mod_val, int force_adj,mapping action)
{   string result,str;
    int me_force,v_dodge;
    object vweapon;
    int damage, damage_bonus,defense_factor,wounded;
    mixed foo;	 
 
          if( force_adj > mod_val*3/4 )
	      	
	     	return HIG"$n轻轻一拨，$N招式向旁边稍微歪了一下。\n"NOR;
	     
          
else{
     	        if (!vweapon=victim->query_temp("weapon")) 
          	result = HIG"$n轻轻一拨，$N顿时觉得内力逆转，拳头向着自己的身体直撞过去！\n"NOR;
          	else result =HIG"$n轻轻一拨，$N顿时觉得内力逆转，"+vweapon->name()+HIG"向着自己的身体直撞过去！\n"NOR;
          	
          	me_force = COMBAT_D->skill_power(me, "force", SKILL_USAGE_ATTACK); if( me_force < 1) me_force = 1;
                v_dodge  = COMBAT_D->skill_power(victim, "dodge", SKILL_USAGE_DEFENSE); if( v_dodge < 1) v_dodge = 1;
                
                       
       if ( random(me_force) < random(v_dodge) )
                {result += random(2) ? "$N一个懒驴打滚，灰头土脸的躲开了。\n" : "但$N早有准备，结果$n连边都没沾上。\n";
          	 return result;
          	}
          	     
       else  { 
                damage = victim->query_temp("apply/damage");
                wounded = 0;
                if( action["damage"] )  damage += action["damage"] * damage / 100;
                damage_bonus = victim->query_str();
                if( me->query("force_factor") && (me->query("force") > me->query("force_factor")) )   
                     {damage_bonus += me->query("force_factor");
                      me->add("force",-victim->query("force_factor"));
                     }
                if( victim->query("force_factor") && (victim->query("force") > victim->query("force_factor")) )   
                     {damage_bonus += victim->query("force_factor");
                      victim->add("force",-victim->query("force_factor"));
                     }
                damage += (damage_bonus + random(damage_bonus))/2;
                defense_factor = victim->query("combat_exp");
			while( random(defense_factor) > me->query("combat_exp") ) 
			{damage -= damage / 3;}
		damage = victim->receive_damage("kee", damage, me );
		if( (me->is_killing(victim) || vweapon) && random(damage) > (int)victim->query_temp("apply/armor") ) 
		      {victim->receive_wound("kee",damage - (int)victim->query_temp("apply/armor"), me);
                       wounded=1;
                      }
                str = COMBAT_D->damage_msg(damage, action["damage_type"]);
                str = replace_string( str, "$n", "$N" );
                str = replace_string( str, "$p", "$N" );
                result += str;
                if ( damage > 0 && wounded)  result += "( $N" + COMBAT_D->eff_status_msg(
			       (int)victim->query("eff_kee") * 100 /(1+(int)victim->query("max_kee")) ) 
			       + " )\n";
                          else result +=   "( $N" + COMBAT_D->status_msg(
			       (int)victim->query("kee") * 100/(1+(int)victim->query("max_kee")) ) 
			       + " )\n";              
                    return result;
             }
       }
}


