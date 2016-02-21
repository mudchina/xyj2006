//Cracked by Roath

//六道轮回

#include <ansi.h>
 
inherit F_DBASE;
inherit SSERVER;
 
void delay_effect(object me, object target, object weapon,int power);
 
int perform(object me, object target)
{
        int delay,skill;
        object weapon=me->query_temp("weapon");
        //if (!wizardp(me)) return notify_fail("你不会。\n");
        if (!target) return notify_fail("打谁？\n");
        if (!me->is_fighting(target))
          return notify_fail("你们不在打架。\n");
        skill=me->query_skill("tonsillit",1);        
        if (skill<60) return notify_fail("你的摄气诀不够纯熟。\n");
		if(me->query("family/family_name") != "阎罗地府")
                return notify_fail(HIG"「炼狱」"+NOR"是冥界不传之密！\n");
        skill=me->query_skill("whip");
        if (skill<100) 
           return notify_fail("你的鞭法太差劲了。\n"); 
        if( (int)me->query("force") < 300 )      
                return notify_fail("你的内力不够。\n");
        if( (int)me->query_temp("lunhui_delay") )
                return notify_fail("你已经在施展炼狱了。\n");
        
        me->add("force", -200);
delay=random(2)+1;
        message_vision(HIB"$N阴恻恻地一笑，手中"+weapon->name()+
             HIB"突然慢了下来，$n一见大喜，抓住机会，上前就是一轮疾攻！\n"NOR, me,target);
//        tell_object(me,delay+"\n");
        me->set_temp("lunhui_delay", 1);
me->start_busy(delay);
        me->start_call_out( (: call_other, __FILE__, "delay_effect", 
me, target,weapon,delay:), delay);
 
         return 1;
}
 
void delay_effect(object me,object target,object weapon,int power)
{
        mapping action;
        mapping new_act=([]);
        int attack,damage;
        
        me->delete_temp("lunhui_delay");
      if (!target) return;
        if (environment(me)!=environment(target)) return;
        if (me->query_temp("weapon")!=weapon) return;

        message_vision(HIR"$N鞭势突然一变，手中"+weapon->name()+
            HIR"幻做漫天鞭影，将$n的退路全部封死。\n"NOR,me,target);
        message_vision(HIR"$N觉得有如置身炼狱，四周都是熊熊鬼火，深受轮回之苦，连气都透不过来。\n"NOR,target);

        me->set("actions", (: call_other, SKILL_D("hellfire-whip"), "query_pfm_action" :) );

        attack=me->query_temp("apply/attack");
        damage=me->query_temp("apply/damage");
        me->add_temp("apply/attack",me->query_skill("hellfire-whip") *power);
        me->add_temp("apply/damage",damage*power+me->query("force_factor"));
        COMBAT_D->do_attack(me, target, weapon);
        me->set_temp("apply/attack",attack);
        me->set_temp("apply/damage",damage);
        me->reset_action();
 me->start_busy(2);target->start_busy(1);
}
