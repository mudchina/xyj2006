#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
 object weapon;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("天霸封神只能对战斗中的对手使用。\n");
        weapon = me->query_temp("weapon");
        if(me->query("family/family_name")!="昆仑山玉虚洞")
        return notify_fail("天霸封神只有昆仑山玉虚洞门人才可以用！\n");
        if (me->query_skill("wugou-jian",1) < 120)
        return notify_fail("你的吴钩剑法还不够纯熟。\n");
        if (me->query_skill("lingyunbu",1) < 120)
        return notify_fail("你的凌云步还不够纯熟。\n");
        if (me->query_skill_mapped("force")!="xuanzong-force")
        return notify_fail("天霸封神必须和玄宗心法配合。\n");
         if((int)me->query("force") < 1000 )
                return notify_fail("你的内力不够！\n");
        if((int)me->query("kee") < 100 )
                return notify_fail("你的气血不足，没法子施用外功！\n");
        extra = me->query_skill("wugou-jian",1) / 10;
        extra += me->query_skill("lingyunbu",1) / 15;
        me->add_temp("apply/attack", extra);
        me->add_temp("apply/damage", extra);
        me->receive_damage("kee", 150);
msg = MAG  "$N凝聚起天地间诸神的无边力量，一式"+HIW"－天－霸－封－神 －"MAG+"如急电般劈向$n！\n" NOR;
        message_vision(msg, me, target);
 msg = HIW                                                                  "$N手中"+ weapon->name()+  HIW"幻出奇异的光华刺向$n！" NOR;
        message_vision(msg, me, target);
        COMBAT_D->do_attack(me, target,weapon);
msg = HIW  "$N手中"+ weapon->name()+  HIW"发出摄人心魄的呼啸向$n挥去！" NOR;
        message_vision(msg, me, target);
        COMBAT_D->do_attack(me, target,weapon);
msg = HIW  "$N手中"+ weapon->name()+  HIW"竟然发出妙不可言的奇香扑向$n！" NOR;
        message_vision(msg, me, target);
        COMBAT_D->do_attack(me, target,weapon);
        me->add("force",-random(2)*me->query("force_facter")-150);
        me->add_temp("apply/attack", -extra);
        me->add_temp("apply/damage", -extra);
       me->start_busy(1+random(1));
        return 1;
}
