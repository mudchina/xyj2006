#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        object weapon;
        int i;
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展这一招「天地同寿」？\n");
         if(me->query("family/family_name") != "五庄观" )
                return notify_fail("你是哪儿偷学来的武功，也想用「天地同寿」?\n");
        if(!me->is_fighting())
                return notify_fail("「天地同寿」只能在战斗中使用！\n");

        if((int)me->query("max_force") < 1000 )
                return notify_fail("你的内力不够！\n");

        if((int)me->query("force") < 1000 )
                return notify_fail("你的内力不足！\n");

        if((int)me->query("sen") < 500 )
                return notify_fail("你的精神不足，没法子施用外功！\n");
              
        if (me->query_skill_mapped("force")!="zhenyuan-force")
                return notify_fail("天地同寿必须配合镇元神功才能使用。\n");
          


   i=(int)me->query_skill("xiaofeng-sword",1)+(int)me->query_kar();

        if( i < 120)
                return notify_fail("你的晓风残月剑级别还不够，使用这一招会有困难！\n");

   message_vision(HIW"\n$N清啸一声：使出了一招「天地同寿」！\n"NOR,me);

   me->delete("env/brief_message");
   target->delete("env/brief_message");

   me->set_temp("XFJ_perform", 9);
   COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

   me->delete_temp("XFJ_perform");

   me->receive_damage("sen", 100+random(100));
   me->add("force", -200);

   if( !target->is_fighting(me) ) {
         if( living(target) ) {
         if( userp(target) ) target->fight_ob(me);
         else target->kill_ob(me);
                }
        }

        me->start_busy(2);
        return 1;
}

