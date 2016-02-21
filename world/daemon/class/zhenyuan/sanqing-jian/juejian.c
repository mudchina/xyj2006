#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        object weapon;
                
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展这一招「三清绝剑」？\n");
         if(me->query("family/family_name") != "五庄观")
                return notify_fail("[三清绝剑]是五庄观不传之密！\n");

        if(!me->is_fighting())
                return notify_fail("「三清绝剑」只能在战斗中使用！\n");

        if((int)me->query("max_force") < 500 )
                return notify_fail("你的内力不够！\n");

            if((int)me->query("force") < 500 )
                        return notify_fail("你的内力不足！\n");

        if((int)me->query("sen") < 100 )
                return notify_fail("你的精神不足，没法子施用外功！\n");

        if((int)me->query_skill("sanqing-jian", 1) < 120)
                return notify_fail("你的三清剑法级别还不够，使用这一招会有困难！\n");
               
               if (me->query_skill_mapped("force")!="zhenyuan-force")
                return notify_fail("三清绝剑必须配合镇元神功才能使用。\n");
          
              me->delete("env/brief_message");
            target->delete("env/brief_message");

message_vision(HIC"\n$N深深吸了一口真气，足尖轻轻点地，身形腾空而起，凌空向$n使出了［三清绝剑］！\n"NOR,me,target);

        me->set_temp("SQJ_perform", 4);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->set_temp("SQJ_perform", 2);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->set_temp("SQJ_perform", 5);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->set_temp("SQJ_perform", 6);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        
        me->delete_temp("SQJ_perform");

        me->receive_damage("sen", 100);
        me->add("force", -100);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

        me->start_busy(2);
        return 1;
}



