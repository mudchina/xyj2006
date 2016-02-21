#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra,i,lmt;
        object weapon;

        extra = me->query_skill("huntian-jian",1)/10+me->query_skill("sword",1)/10;
        if ( extra < 20) return notify_fail("你的混天一剑与基本剑法还不够等级！\n");

  if(me->query_skill("xuanzong-force",1) < 100)
    return notify_fail("你的玄宗心法还欠火候，怕是使保护出 [麟生雾彩]。\n");

        if((string)me->query_skill_mapped("force")!="xuanzong-force")
        return notify_fail("麟生雾彩必须以麟生雾彩玄宗心法为底子。\n");
//   if( me->query_temp("pfmxue") ) 
//  return notify_fail("你正在全身运用天下有雪。\n");

if(me->query("max_force") < 1000)
      return notify_fail("你的内力不足。\n");
if(me->query("force") < 1000)
return notify_fail("你的内力不足。\n");

       if( !target ) target = offensive_target(me);
       if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［麟生雾彩］只能对战斗中的对手使用。\n");

        weapon = me->query_temp("weapon");

        msg = HIY  "$N双手持剑，平地随之升起一团彩雾，手中"+ weapon->name()+  HIY "也有如狂漫天飞雨般地向$n"+HIY"卷来！ "NOR+" \n"
                         
          HIR"--------------"+HIY"手中一招 "+HIC"[麟生雾彩] "HIY+"转眼而出"HIR+"-----------------"NOR;

        message_vision(msg,me,target);

        me->add_temp("apply/attack",extra);
        me->add_temp("apply/damage",extra);
        lmt = 9;
        for(i=5;i<=lmt;i++)
        {
        me->set_temp("FMZ_perform",i);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR);
        }
        me->add_temp("apply/attack",-extra);
        me->add_temp("apply/damage",-extra);
        me->add("force",-300);
         me->delete_temp("FMZ_perform");
        me->start_busy(1+random(2));
        return 1;
}
