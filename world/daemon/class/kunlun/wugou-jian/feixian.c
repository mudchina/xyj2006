#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
object weapon;
        if(me->query("family/family_name")!="昆仑山玉虚洞")
        return notify_fail("[天外飞仙]只有昆仑山弟子才可以用！\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("[天外飞仙]只能对战斗中的对手使用。\n");
        if (me->query_skill("wugou-jian",1) < 60)
        return notify_fail("你的吴钩剑法还不够纯熟！\n");
         if((int)me->query("force") < 1000 )
                return notify_fail("你的内力不够！\n");
         if((int)me->query("max_force") < 200 )
                return notify_fail("你的内力不够！\n");
        extra = me->query_skill("wugou-jian",1) / 15;
        me->add_temp("apply/attack", extra);
        me->add_temp("apply/damage", extra);
      weapon=me->query_temp("weapon");
msg = HIC"腾空式！\n$N手中"+weapon->query("name")+HIC"幻出朵朵寒光！\n"NOR;
message_vision(msg,me,target);
        COMBAT_D->do_attack(me, target,me->query_temp("weapon"));
msg = HIW"追云式！\n刹那间$n被罩在剑气之中！\n"NOR;
message_vision(msg,me,target);
        COMBAT_D->do_attack(me, target,me->query_temp("weapon"));
msg = HIY"追仙式！\n$N宛如飘雪一般潇洒飘逸，$n顿时不知如何接招！\n"NOR;
message_vision(msg,me,target);
        COMBAT_D->do_attack(me, target,me->query_temp("weapon"));
    me->add("force",-random(2)*me->query("force_factor")-200);
        me->add_temp("apply/attack", -extra);
        me->add_temp("apply/damage", -extra);
if (me->query_skill("wugou-jian",1) > 60&&me->query_skill("lingyunbu",1)>60)
{
msg = HIR"飞仙式！\n$N犹如天外飞仙一般，披着雪花从空中落下，挥动"+weapon->name()+HIR"向$n斩去! \n"NOR;
message_vision(msg,me,target);
        COMBAT_D->do_attack(me, target,me->query_temp("weapon"));
me->add("force",-random(2)*me->query("force_factor")-100);
        target->add("kee",-250);
}
       me->start_busy(2);
        return 1;
}
