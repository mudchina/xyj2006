#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
        string msg;
        int damage, ap, dp;

        if( !target ) target = offensive_target(me);
        if((string)me->query("family/family_name") != "陷空山无底洞")
                return notify_fail("老鼠用蒸笼是来吃人肉的，你看到人肉还不得吐呀！\n");
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁使用“蒸笼”？\n");

        if((int)me->query("mana") < 80+(int)me->query("mana_factor") )
                return notify_fail("你的法力不够！\n");

        if((int)me->query("sen") < 10 )
                return notify_fail("你无法集中精力念咒！\n");

        me->add("mana", -80-(int)me->query("mana_factor"));
        me->receive_damage("sen", 10);

        if( random(me->query("max_mana")) < 50 ) {
                write("你失败了！\n");
                return 1;
        }

        msg = HIG
"$N口中念了几句咒文，刹时间，空中出现一个巨大的蒸笼，向着$n扣了下来。\n只见那蒸笼里写着一个巨大的“妖”字，仿佛要将$n所有的气血都吸了去…！\n" NOR;

        ap = me->query_skill("spells");
        ap = ( ap * ap * ap / (4 * 400) ) * (int)me->query("sen");
        ap += (int)me->query("combat_exp");
        dp = target->query("combat_exp");
        if( random(ap + dp) > dp ) {
                damage = (int)me->query("max_mana") / 10 +
random((int)me->query("eff_sen") / 5);
                damage -= (int)target->query("max_mana") / 10 +
random((int)target->query("eff_sen") / 5);
         damage +=(int)me->query("mana_factor")-random((int)target->query("mana_factor"));
//here we can see if 2 players are at same status, the attacker has higher chance.
                if( damage > 0 ) {
//finally damage also depends on enabled spells level.
     damage +=random((damage*(int)me->query_skill("spells"))/100);
                        msg += HIW "$n想飞身躲开，没想到却被一块石头拌倒……被蒸笼扣在里面！\n" NOR;
                        target->receive_damage("sen", damage, me);
                        target->receive_wound("sen", damage/3, me);
                        target->receive_damage("kee", damage, me);
                        target->receive_wound("kee", damage/4, me);
                        me->improve_skill("yaofa", 1, 1);
                }
       else {
//here, cast failed and the target's mana_factor will be added to the previous 
//damage to hurt yourself:(...note, damage<0.
                        msg += HIW "$n看$N正在念咒，心里好奇，也学着念了几句，没想到蒸笼掉转方向扣住了$N。\n" NOR;
     damage -= (int)target->query("mana_factor");
     damage -=random((-damage*(int)target->query_skill("spells"))/100);
                        me->receive_damage("sen", -damage, target);
                        me->receive_wound("sen", -damage/3, target);
                        me->receive_damage("kee", -damage, target);
                        me->receive_wound("kee", -damage/4, target);
                        me->improve_skill("yaofa", 1, 1);
       }
             } 
   else
                msg += HIW "$n见蒸笼下自己扣了过来，飞身跳向一旁，将此招躲开！\n" NOR;

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

        me->start_busy(1+random(2));
        return 3+random(5);
}
