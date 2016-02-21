//write by yesi

#include <ansi.h>

inherit SSERVER;
void check_fight(object me);
void remove_effect(object me);


int perform(object me, object target)
{
        object weapon;
	int i,j;
		        
	if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                {if(me->query_temp("ldlh")) {remove_effect(me);return 1;}
                  else	return notify_fail("你要对谁施展「六道轮回」？\n");}
        
        if(time()-(int)me->query_temp("ldlh_end") < 10) return notify_fail("不能频繁出入「六道轮回」！\n");

        
        if(me->query_temp("ldlh")) {remove_effect(me);return 1;}
        
            
        if(!me->is_fighting())
                return notify_fail("「六道轮回」只能在战斗中使用！\n");

        if(me->query("family/family_name") != "阎罗地府")
                return notify_fail("[六道轮回]是阎罗地府不传之密！\n");
        
        if((int)me->query("force") < 1000 )
                return notify_fail("你的内力不够！\n");

        if((int)me->query("kee") < 300 )
                return notify_fail("你的气血不足，没法子施用外功！\n");
        
        if (me->query_skill_mapped("force")!="tonsillit")
            return notify_fail("「六道轮回」必须配合摄气诀才能使用。\n");
              
        if (me->query_skill_mapped("spells")!="gouhunshu")
            return notify_fail("「六道轮回」必须配合勾魂术才能使用。\n");
        
        if((int)me->query_skill("hellfire-whip", 1) < 150)
                return notify_fail("你的烈火鞭级别还不够，使用这一招会有困难！\n");
        
        if((int)me->query_skill("gouhunshu", 1) < 100)
                return notify_fail("你的勾魂术级别还不够，布不了「六道轮回」迷阵！\n");
        
        weapon=me->query_temp("weapon");
        
       
        message_vision(HIW"\n$N口中念念有词：般若波罗密，般若波罗密，苦难众生与我共堕六道，再渡轮回。\n"NOR,me);
        me->set_temp("lunhui",0);
        me->set_temp("ldlh",1);
        me->set_temp("ldlh_time",60+random((me->query_skill("force")+me->query_skill("whip"))/6));
        
        call_out("check_fight", 1, me);
        return 1;
}


void check_fight(object me)
{
	object weapon;
        if(!me) return;        
	if( !objectp(weapon=me->query_temp("weapon")) ||
		(weapon->query("apply/skill_type") != "whip" &&
		weapon->query("skill_type") != "whip" ) || 
		me->query_skill_mapped("whip") != "hellfire-whip" ||
		me->query_skill_mapped("force") != "tonsillit" ||
		me->query_skill_mapped("spells") != "gouhunshu" ) 
		remove_effect(me);
	else if(me->query_temp("ldlh_time")<1)
	        remove_effect(me);		
	else {  me->add_temp("ldlh_time",-1);
		call_out("check_fight", 1, me);
	     }
}



void remove_effect(object me)
{       if(!me) return;
	remove_call_out("check_fight");
	me->delete_temp("ldlh");
	me->delete_temp("lunhui");
	message_vision(HIW"$N从「六道轮回」走了出来。\n"NOR, me);
	me->set_temp("ldlh_end", time() );
}


