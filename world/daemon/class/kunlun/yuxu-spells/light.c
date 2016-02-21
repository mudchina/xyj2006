#include <ansi.h>
inherit SSERVER;
int cast(object me, object target)
{
        int success_adj, damage_adj;
        success_adj = 100;
        damage_adj = 100;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展五行神光？\n");
        if((int)me->query("mana") < 100+2*(int)me->query("mana_factor") )
                return notify_fail("你的法力不够！\n");
        if((int)me->query("sen") < 100 )
                return notify_fail("你无法集中精力！\n");
        me->add("mana", -25-2*(int)me->query("mana_factor"));
        me->receive_damage("sen", 50);
        if( random(me->query("max_mana")) < 50 )
{
                write("糟了，神光没放出来。\n");
                return 1;
}
        SPELL_D->attacking_cast(
                me, 
                target, 
                success_adj,
                damage_adj,
                "qi",
                HIC "\n$N口中念了句咒文，背后出现青、黄、赤、白、黑五道光华，一声响指之后，神光一齐射向$n！\n" NOR,
                HIR "\n结果「嗤」地一声，五色神光从$n身上透体而过，\n拖出一条长长的血箭，将方圆五丈夷为平地！\n" NOR, 
                HIC "结果嗤！地一声$n侧身闪过。还好只擦到头皮。\n" NOR, 
                HIC "但是这五色神光被$n以法力反激，反向$N射去！\n" NOR, 
                HIR "结果五色神光从$n身上透体而过，拖出一条长长的血箭，将方圆五丈夷为平地！\n" NOR
        );
        me->start_busy(1+random(2));
        return 3+random(6);
}
