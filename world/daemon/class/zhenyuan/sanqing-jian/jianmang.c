
//jianmang.c
//write by yesi

#include <ansi.h>

 
void remove_effect(object me);
void check(object me);

int perform(object me, object target)
{
        int skill_sanqing, skill_sword, skill_force,skill_spells,attack_amount;
        object weapon=me->query_temp("weapon");
        
        skill_force=me->query_skill("zhenyuan-force",1);
        if( skill_force > 250 ) skill_force=250;
	
	skill_spells=me->query_skill("taiyi",1);
	
	skill_sanqing = me->query_skill("sanqing-jian"); 
	attack_amount=(skill_spells+skill_force)/2-50;
        
        if( me->query_temp("jianmang") )  {remove_effect(me); return 1;}
        
        if( time()-(int)me->query_temp("jianmang_end") < 10 )
                   return notify_fail("你现在真气不纯。\n");
                   
        if (skill_force < 100) return notify_fail("你的镇元神功修为不够，产生不了剑芒。\n");

        if (skill_spells < 100) return notify_fail("你的太乙仙法修为不够，产生不了剑芒。\n");
        
        if (me->query_skill_mapped("force")!="zhenyuan-force")
            return notify_fail("「剑芒」必须配合镇元神功才能使用。\n");
              
        if (me->query_skill_mapped("spells")!="taiyi")
            return notify_fail("「剑芒」必须配合太乙仙法才能使用。\n");
        
        if((int)me->query_skill("sanqing-jian", 1) < 160)
                return notify_fail("你的三清剑法级别还不够，怎能生成剑芒！\n");

                      
            if( (int)me->query("force") < 150 )      
            return notify_fail("你的内力不够。\n");
        
		        
        me->add("force", -skill_force);
       
        message_vision(HIY"$N催动真气，同时念动真言，将镇元神功和太乙法力缓缓注入"+weapon->name()+HIY"，渐渐长出五寸剑芒，烁烁生辉。\n" NOR, me);
        me->add_temp("apply/damage",attack_amount);  
        me->set_temp("jianmang_damage",attack_amount);
	me->set_temp("jianmang", 1);
        me->set_temp("jianmang_time",skill_force);
        call_out("check", 1, me);
         
         return 1;
}
 

void check(object me)
{      
	object weapon;
if(!me) return;
	             
if(!me->query_skill_mapped("force")) remove_effect(me);
	if(me->query_skill_mapped("sword") != "sanqing-jian"
	|| me->query_skill_mapped("force") != "zhenyuan-force" 
	|| me->query_skill_mapped("spells") != "taiyi" 
	|| !objectp(weapon=me->query_temp("weapon")) 
	|| (weapon->query("apply/skill_type") != "sword" 
	&&  weapon->query("skill_type") != "sword" )) 
		remove_effect(me);			
	else if(me->query_temp("jianmang_time")<1)
	remove_effect(me);			
	else {  me->add_temp("jianmang_time",-1);
		call_out("check", 1, me);
	     }
	
}



void remove_effect(object me)
{       
        if(!me) return;
        me->add_temp("apply/damage", -me->query_temp("jianmang_damage"));
        remove_call_out("check");
        me->delete_temp("jianmang");
        message_vision(HIB"$N的剑芒渐渐褪去。\n" NOR, me);
        me->set_temp("jianmang_end",time());
}


