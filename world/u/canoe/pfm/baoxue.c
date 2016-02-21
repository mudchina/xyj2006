#include <ansi.h>
inherit SSERVER;
int perform(object me, object target)
{
object weapon;
int damage;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展这一招「暴雪天威」？\n");
    if(!wizardp(me)&&(string)me->query("family/family_name") != "大雪山" )
   return notify_fail("你的冰魄寒刀是从哪里偷学来的？\n");
        if(!me->is_fighting())
                return notify_fail("「暴雪天威」只能在战斗中使用！\n");
        if((int)me->query("max_force") < 500 )
                return notify_fail("你的内力不够！\n");
        if((int)me->query("force") < 500 )
                return notify_fail("你的内力不足！\n");
        if((int)me->query("sen") < 500 )
                return notify_fail("你的精神不足，没法子施用外功！\n");
        if((int)me->query_skill("bingpo-blade", 1) < 100)
                return notify_fail("你的冰魄寒刀级别还不够，使用这一招会有困难！\n");
        if (me->query_temp("xs_pfm_busy")) return notify_fail("绝招用的太多太滥就不灵了。\n");
 message_vision(HIC"\n$N运起寒气，身形一转，四周顿时冰冻数尺，空气中寒气逼人$n只冻的忘记的抵抗！\n"NOR,me,target);
 me->set_temp("noauto",1);
 target->start_busy(random(2));
 damage=random(((int)me->query_skill("blade")));
 target->receive_wound("kee",damage);
 message_vision(HIC"\n$N嘿嘿一声冷笑，竟然隐入雪花之中。$n大急，四下找寻$N，忽然背后一阵寒气随着\n"NOR,me,target);
 message_vision(HIC"\n刀光狂袭过来！！！\n"NOR,me,target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
 if(random(me->query("combat_exp"))>random(target->query("combat_exp"))/2)
 {
message_vision(HIY"\n打斗中,一只金色大鹏鸟远远飞来！$N和$n都看呆了！\n"NOR,me,target);
message_vision(HIY"\n突然大鹏鸟用翅膀一扇,顿时狂风大作！\n"NOR,me,target);
if(me->query("force_factor")>random(target->query("force_factor")))
{
 message_vision(HIR"\n$N见机不可失,连忙攻出一招！\n"NOR,me,target);
 target->receive_damage("kee",damage*2); 
 target->receive_damage("sen",damage*2); 
 message_vision(HIR"\n狂风夹杂着碎石漫天飞舞,把$n砸得遍体鳞伤！\n"NOR,me,target);
 target->receive_wound("kee",damage);
 target->receive_wound("sen",damage);
 COMBAT_D->report_status(target);
}  
 else if(random(me->query("force_factor"))>target->query("force_factor")/2)
{
message_vision(HIR"\n狂风夹杂着碎石漫天飞舞,把$n砸得遍体鳞伤！\n"NOR,me,target);
target->receive_wound("kee",damage);
COMBAT_D->report_status(target);
}
else  
{
message_vision(HIR"\n狂风夹杂着碎石漫天飞舞,把$N和$n砸得遍体鳞伤！\n"NOR,me,target); 
target->receive_wound("kee",damage);
target->receive_wound("sen",damage);
COMBAT_D->report_status(target);
me->receive_wound("kee",damage/10);
COMBAT_D->report_status(me);
}        
}
 me->delete_temp("noauto");
 me->receive_damage("sen", 100);
 me->add("force", -500);
/* if( !target->is_fighting(me) ) {
               if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

*/
          me->start_busy(2);
      me->set_temp("xs_pfm_busy",1);
//  me->set_temp("no_move",1);
//  call_out("remove_no_move",5,me);
        call_out("remove_effect",2+random(3),me);
        return 1;
}

void remove_effect(object me) {
  if (!me) return;
  me->delete_temp("xs_pfm_busy");
}
/*
void remove_no_move(object me) {
  if (me) me->delete_temp("no_move");
}
*/
