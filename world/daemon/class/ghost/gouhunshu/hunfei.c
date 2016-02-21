//Cracked by Roath
#include <ansi.h>
inherit SSERVER;
int cast(object me, object target)
{
        string msg;
        int damage, ap, dp;
        int extradam;

        if( !target ) target = offensive_target(me);

        if((int)me->query_skill("gouhunshu",1) < 100 )
                return notify_fail("你的勾魂术不够高！\n");
        if(me->query("family/family_name")!="阎罗地府")
                return notify_fail("你不是地府弟子，不能使用这项技能！\n");
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展魂飞魄散？\n");

        if((int)me->query("kee") < 25 )
                return notify_fail("你的气血不够！\n");

        me->receive_wound("kee", 25);
        msg = HIC "$N口中不断的念着咒文，只见阴气不停的向$n扑去！\n\n" NOR;

        ap = me->query_skill("gouhunshu");
        extradam = ap/2;
        ap = ( ap * ap /100 * ap / 4 ) * (int)me->query("sen") ;
        dp = target->query("combat_exp");
        if( random(ap + dp) > dp ) {
                damage = me->query("bellicosity") /50 ;
                        msg +=  RED "阴气逐渐包围了$p的身体!\n" NOR;
                         message_vision(msg, me, target);
                         if (damage > 1000) damage = 975 + random(50);
                        target->receive_damage("kee", damage, me);
                        target->receive_wound("kee", damage/3, me);
                        if( damage > 0 ) COMBAT_D->report_status(target);

        } else
                {
                msg += "但是被$n发现了！！\n";
                message_vision(msg, me, target);
                target->kill_ob(me);
                me->kill_ob(target);
                }
        me->start_busy(2);
        return 1;
}

