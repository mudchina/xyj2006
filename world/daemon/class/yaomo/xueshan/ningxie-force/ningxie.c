
//ningxie-force凝血大法
#include <ansi.h>
inherit SSERVER;
int exert(object me, object target)
{
        int lvl,lvl2;
        if(me->query("family/family_name")!="大雪山")
          return notify_fail("冰谷凝血功只有雪山弟子才可以用！\n");
        if( !me->is_fighting() )
                return notify_fail("只能在战斗中对敌人使用！\n");
        lvl = me->query_skill("ningxie-force",1);
    if(!target)target = offensive_target(me);
if(target==me) target = offensive_target(me);
        if( (int)me->query("force") < 500 )
                return notify_fail("你的真气不够。\n");
        if( lvl < 100 )
return notify_fail("你的【冰谷凝血功】火候太浅，用不出“凝血大法”！\n");
lvl = me->query_skill("force")*me->query("force")/me->query("max_force");
if(target->query_skill("force")&&target->query("max_force")&&(target))
lvl2 = target->query_skill("force")*target->query("force")/target->query("max_force");
else lvl2=0;
message_vision(HIW+"$N脸色一寒，浑身发出冰雪般的寒气。\n"+NOR,me);
if(random((me->query("combat_exp")))>(int)target->query("combat_exp")/2 )
{
         message_vision(
                HIW +
"$N躲闪不及，被$n发出的寒气裹个正着！\n$N的全身都冻僵了！\n"+NOR,target,me);
target->receive_damage("kee",target->query("kee")/4);
target->receive_wound("kee",target->query("kee")/4);
       target->set_temp("last_damage_from", me);
target->start_busy(lvl/(lvl2+1)+1);
}
else
{
         message_vision(
                HIW +
"$N觉出危险，身行急退，躲开了此式！\n"+NOR,target);
}
        me->add("force", -500);
me->start_busy(1+random(2));
return 1;
}
