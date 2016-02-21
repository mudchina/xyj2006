// dizang.c
// hell 的法术
#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
        string msg;
        int damage, ap, dp;

        if( !target ) target = offensive_target(me);
        if(me->query("family/family_name")!="阎罗地府")
                return notify_fail("你不是地府弟子，不能使用这项技能！\n");

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要请地藏菩萨制裁谁？\n");

        if((int)me->query("mana") < 200+(int)me->query("mana_factor") )
                return notify_fail("你的法力不够！\n");

        if((int)me->query("sen") < 50 )
                return notify_fail("你无法集中精力呼唤地藏菩萨！\n");

        me->add("mana", -100-(int)me->query("mana_factor"));
        me->receive_damage("sen", 50);

        if( random(me->query("max_mana")) < 100 ) {
                write("你失败了！\n");
                return 1;
        }

        msg = HIY
"$N口中念了几句咒文，虔诚地祈求地藏菩萨助$N御敌。\n一阵烟雾中地藏菩萨现形了。手中的缚龙索诡异地抽向$n！\n" NOR;

        ap = me->query_skill("spells");
        ap = ( ap * ap * ap / (4 * 400) ) * (int)me->query("sen");
        ap += (int)me->query("combat_exp");
        dp = target->query("combat_exp");
        if( random(ap + dp) > dp /4) {
                damage = (int)me->query("max_mana") / 2 +
random((int)me->query("eff_sen") / 2);
                damage -= (int)target->query("max_mana") / 2 +
random((int)target->query("eff_sen") / 2);
                damage +=(int)me->query("mana_factor")-random((int)target->query("mana_factor"));
//here we can see if 2 players are at same status, the attacker has higher chance.
                if( damage > 0 ) {
//finally damage also depends on enabled spells level.
                damage +=random((damage*(int)me->query_skill("spells"))/100);
                        msg += HIC "结果$n被抽个正着，血花飞溅，受伤不轻！\n" NOR;
                        target->receive_damage("sen", damage, me);
                        target->receive_wound("sen", damage/3, me);
                        target->receive_damage("kee", damage, me);
                        target->receive_wound("kee", damage/4, me);
                        me->improve_skill("gouhunshu", 1, 1);
                }
            else {
//here, cast failed and the target's mana_factor will be added to the previous 
//damage to hurt yourself:(...note, damage<0.
                        msg += HIC "结果缚龙索被$n以法力反激，反而抽中了$N！\n" NOR;
                damage -= (int)target->query("mana_factor");
                damage -=random((-damage*(int)target->query_skill("spells"))/100);
                        me->receive_damage("sen", -damage, target);
                        me->receive_wound("sen", -damage/3, target);
                        me->receive_damage("kee", -damage, target);
                        me->receive_wound("kee", -damage/4, target);
           //             me->improve_skill("gouhunshu", 1, 1);
            }
             } 
        else
                msg += "但是被$n躲开了。\n";

        message_vision(msg, me, target);
        if( damage > 0 ) COMBAT_D->report_status(target);
        else if( damage < 0 ) COMBAT_D->report_status(me);
//damage=0 corresponding to "但是被$n躲开了。\n"--no report.    

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else
target->kill_ob(me);
                }
                me->kill_ob(target);
        }

        me->start_busy(2+random(2));
        return 1;
}

