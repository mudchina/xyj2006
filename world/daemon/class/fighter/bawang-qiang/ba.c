
//ba.c
//write by yesi

#include <ansi.h>

 
void remove_effect(object me);
void check(object me);

int perform(object me, object target)
{
        int skill_force,attack_amount;
        object weapon=me->query_temp("weapon");
        
        skill_force=me->query_skill("lengquan-force",1);
        if( skill_force > 250 ) skill_force=250;
		
	attack_amount=skill_force/5;
        
        if( me->query_temp("bawang") )  {remove_effect(me);return 1;}
        
        if( time()-(int)me->query_temp("bawang_end") < 10 )
                   return notify_fail("你现在真气不纯。\n");
                   
        if (skill_force < 60) return notify_fail("你的冷泉神功修为不够，运行不了霸字诀。\n");
        
        if (me->query_skill_mapped("force")!="lengquan-force")
            return notify_fail("霸字诀必须配合冷泉神功才能使用。\n");
                
        if((int)me->query_skill("bawang-qiang", 1) < 120)
                return notify_fail("你的霸王枪法级别还不够，运行不了霸字诀。\n");

                      
            if( (int)me->query("force") < 150 )      
            return notify_fail("你的内力不够。\n");
        
		        
        me->add("force", -skill_force);
       
        message_vision(HIR"$N力贯双臂，运行起冷泉神功，手中"+weapon->name()+HIR"发出一阵龙吟！\n" NOR, me);
        me->add_temp("apply/damage",attack_amount);  
	me->add_temp("apply/spear",attack_amount);
	me->add_temp("apply/courage",30);
	me->set_temp("bawang", 1);
	me->set_temp("bawang_time",skill_force);
        call_out("check", 1, me);
        call_out("remove_effect",skill_force,me,attack_amount);
 
         return 1;
}
 

void check(object me)
{      
	object weapon;
	if(!me) return;             
	if(me->query_skill_mapped("spear") != "bawang-qiang"
	|| me->query_skill_mapped("force") != "lengquan-force" 
	|| !objectp(weapon=me->query_temp("weapon")) 
	|| (weapon->query("apply/skill_type") != "spear" 
	&&  weapon->query("skill_type") != "spear" )) 
		remove_effect(me);			
	else if(me->query_temp("bawang_time")<1)
             remove_effect(me);
         else {  me->add_temp("bawang_time",-1);
                call_out("check", 1, me);
              }
}



void remove_effect(object me)
{       
        int skill;
        if(!me) return;
        skill = me->query_skill("lengquan-force",1)/5; 
        me->add_temp("apply/damage", -skill);
	me->delete_temp("apply/spear");
	me->add_temp("apply/courage",-30);
        remove_call_out("check");
        remove_call_out("remove_effect");
        me->delete_temp("bawang");
        tell_object(me, "你将冷泉神功收回丹田。\n");
        me->set_temp("bawang_end",time());
        me->set_temp("perform_end",time()+2);
}




