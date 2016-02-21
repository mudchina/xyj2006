//Cracked by Roath
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra,i,lmt;
        object weapon;
        extra = me->query_skill("qixiu-jian",1);
        if ( extra < 80) return notify_fail("你的[七修剑]还不够纯熟！\n");
        extra = me->query_skill("huntian-qigong",1);
        if ( extra < 80) return notify_fail("你的[混天气功]还不够纯熟，无法发挥七修剑的威力！\n");
//      if( me->query_temp("zxzx") ) 
//        return notify_fail("你正在运功,不能分心他用！\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［夺命七剑］只能对战斗中的对手使用。\n");

        if(me->query("family/family_name")!="陷空山无底洞")
                return notify_fail("你不能用别派的特殊攻击\n");

        weapon = me->query_temp("weapon");
        msg = YEL  "$N狂性大发，手中的"+ weapon->name()+  "狂风暴雨般地向$n袭来！" NOR;
        message_vision(msg,me,target);
        me->add_temp("apply/attack",extra/10);
        me->add_temp("apply/damage",extra/10);
        lmt = random(5)+3;
        for(i=1;i<=lmt;i++)
        {
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        }
        me->add_temp("apply/attack",-extra/10);
        me->add_temp("apply/damage",-extra/10);
        me->start_busy(2);
        return 1;
}
