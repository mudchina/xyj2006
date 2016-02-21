//Cracked by Roath
//evil...........2000.4.16
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra,i,lmt;
        object weapon;

        extra = me->query_skill("lunhui-zhang",1)/10+me->query_skill("staff",1)/10;
        if ( extra < 20) return notify_fail("你的轮回杖法与基本杖法还不够纯熟，怕是无法运用！\n");

  if(me->query_skill("lotusforce",1) < 100)
    return notify_fail("你的内功底子不足，无法运杖如风，施展不出降龙伏虎。\n");

        if((string)me->query_skill_mapped("force")!="lotusforce")
        return notify_fail("降龙伏虎必须以莲台心法为底子。\n");

  if(me->query("max_force") < 500)
      return notify_fail("你的内力不足，难以随意挥动一把禅杖。\n");

       if( !target ) target = offensive_target(me);
       if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［降龙伏虎］只能对战斗中的对手使用。\n");

        weapon = me->query_temp("weapon");

        msg = HIY  "$N身型闪动，地面随之起伏一降狂风，手中"+ weapon->name()+  "也有如狂风暴雨般地向$n卷来！" NOR;

        message_vision(msg,me,target);

        me->add_temp("apply/attack",extra);
        me->add_temp("apply/damage",extra);
        lmt = 9;
        for(i=6;i<=lmt;i++)
        {
        me->set_temp("FMZ_perform",i);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR);
        }
        me->add_temp("apply/attack",-extra);
        me->add_temp("apply/damage",-extra);
        me->add("force",-extra*5);
         me->delete_temp("FMZ_perform");
        me->start_busy(3+random(2));
        return 1;
}



