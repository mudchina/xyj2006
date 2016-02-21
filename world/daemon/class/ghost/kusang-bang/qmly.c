#include <ansi.h>


int perform(object me)
{
        string msg;
        object weapon, target;
        int skill, ap, dp, force_wound, qi_wound;

        me->clean_up_enemy();
        target = me->select_opponent();

        skill = me->query_skill("kusang-bang",1);

 if(me->query("family/family_name") != "阎罗地府")
return notify_fail(HIG"「青面獠牙」"+NOR"是冥界不传之密！\n");
        if( !(me->is_fighting() ))
                return notify_fail("「青面獠牙」只能对战斗中的对手使用。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "stick")             
        return notify_fail("使用「青面獠牙」时手里必须拿着根棍。\n");

        if( skill < 100)
                return notify_fail("你的「惊魂掌」等级不够, 不能使用「青面獠牙
」！\n");

        if( me->query_skill("dodge",1) < 120 )
                return notify_fail("你的轻功不够，无法运用「青面獠牙」！\n");

        msg = HIC "$N突然如同「青面獠牙」，欺近$n的身前，张嘴便向$n的咽喉咬去。\
\n"NOR;
        message_vision(msg, me, target);

 	ap = me->query("combat_exp");
        dp = target->query("combat_exp") ;
 		if(random(ap) > dp/2)
        {
                if(userp(me))
                        me->add("force",-100);

                msg = HIG "$n只觉得咽喉一阵剧痛，$N正在狂吸$n的鲜血！\n"NOR;
                force_wound = skill*2 + random(skill);
                target->add("force", -force_wound);
                target->add("kee", -force_wound);
 		me->start_busy(1+random(2));
                if( !target->is_killing(me) ) target->kill_ob(me);
               target->set_temp("last_damage_from",me);
        }
        else
        {
                msg = HIG "只见$n不慌不忙，轻轻一闪，躲过了$N的利齿！\n"NOR;
                if(userp(me))
                        me->add("force",-100);
                me->start_busy(2);
                if( !target->is_killing(me) ) target->kill_ob(me);
}
        message_vision(msg, me, target);
        return 1;
}

