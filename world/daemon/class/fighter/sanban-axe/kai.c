// 开天辟地
// lestat 2001
#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展这一招"+HIM"「开天辟地」"+NOR"？\n");

        if((int)me->query("force") < 150+(int)me->query("force_factor") )
                return notify_fail("你的内力不够！\n");

        if((int)me->query("kee") < 100 )
                return notify_fail("你的气血不足，没法子施用外功！\n");

        if((int)me->query_skill("sanban-axe", 1) <60)
                return notify_fail("你的宣花斧级别还不够！\n");
        
        if(me->query("family/family_name") != "将军府")
                return notify_fail(HIR"「开天辟地」"+NOR"是将军府不传之密！\n");



        me->add("force", -25-(int)me->query("force_factor"));
        me->receive_damage("kee", 100);



        COMBAT_D->attacking_perform(
                me, 
                        //attacker 
                target, 
                        //target
                (int)me->query_skill("sanban-axe", 1), 
                        //level of skill used
                140, 
                        //success adjustment
                100, 
                        //damage adjustment
                "both", 
                        //damage type: could be "qi"/"kee", "shen"/"sen", ...default "both"
                HIC "$N突然暴喝一声，将手中巨斧斜向上举起，然后在半空中划出一
道圆弧，随即径直斜下斩向$n！这一瞬间，$n只觉得呼吸都停止了！\n" NOR,
                        //initial message
                HIW "结果一道寒光从$n当头劈过,带出一地鲜血！\n" NOR, 
                        //success message
                CYN "$n急忙飞身向后跃出数丈，才勉强躲闪过这致命一击！\n" NOR, 
                        //fail message
                HIB "但是被$n以内力一震，寒光一闪,反向$N劈了下来！\n" NOR, 
                        //backfire initial message
                HIB "结果寒光$n身上一掠而过。\n" NOR
                        //backfire hit message. note here $N and $n!!!
        );

        me->start_busy(2+random(2));

        return 3+random(5);
}
