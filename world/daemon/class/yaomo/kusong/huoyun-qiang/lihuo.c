
// 离火三重
// yangwl 1/10/2001  可以加上门派限制

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
        string msg;
        int extra;
        object weapon;
        extra = me->query_skill("huoyun-qiang",1);
        
        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "spear")
                        return notify_fail("你使用的武器不对。\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
               return notify_fail(HIR"「离火三重」"NOR"只能对战斗中的对手使用。\n");
        weapon = me->query_temp("weapon");
        if(extra < 100)
            return notify_fail("你的火云枪法还不够纯熟！\n");
     if(me->query("family/family_name")!="火云洞")
           return notify_fail("“离火三重”只有火云洞门人才可以用！\n");
        if(me->query("max_force") < 500)
            return notify_fail("你的内力还不够，不要勉强了！\n"); 
        if(me->query("force") < 1000)
            return notify_fail("你的真气不够，不要勉强了！\n"); 
              
        
        if(extra >= 400)  extra = 400;
        
        me->add_temp("apply/attack",extra/3);
        me->add_temp("apply/damage",extra/3);
        me->add_temp("apply/strength", extra/10);
        message_vision(HIR"$N手中前指的枪尖突然像着火一般，“砰”地炸出一团紫红色的火焰，绕
着通红透亮的枪身燃烧起来！！“刷”地拉出一道火红中映着紫焰的流光，
哗啦啦地就是一片遮天的火舌，往$n的头上盖去！"NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIR  "$N全身真气外放，衣衫冉冉飘动，双眸倏转妖红！！" NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
message_vision(HIR  "$N手中"+weapon->query("name")+ HIR"内所有阳气已是内燃敛收，放出肉眼难以直视的青白光华！" NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add_temp("apply/attack",-extra/3);
        me->add_temp("apply/damage",-extra/3);
        me->add_temp("apply/strength", -extra/10);

        me->start_busy(2);
        return 1;
}
