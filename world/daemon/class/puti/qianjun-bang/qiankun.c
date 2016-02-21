//Cracked by Roath
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
                return notify_fail("你要对谁施展这一招「乾坤一棒」？\n");
             if(me->query("family/family_name") != "方寸山三星洞" )
                           return notify_fail("你是哪儿偷学来的武功，也想用「乾坤一棒」?\n");

        if(!me->is_fighting())
                return notify_fail("「乾坤一棒」只能在战斗中使用！\n");

        if((int)me->query("max_force") < 1000 )
                return notify_fail("你的内力不够！\n");

        if((int)me->query("force") < 1000 )
                return notify_fail("你的内力不足！\n");

        if((int)me->query("sen") < 500 )
                return notify_fail("你的精神不足，没法子施用外功！\n");

	i=(int)me->query_skill("qianjun-bang",1)+(int)me->query_kar();

        if( i < 150)
                return notify_fail("你的千钧棒级别还不够，使用这一招会有困难！\n");

  if (me->query_temp("fc_pfm_busy")) return notify_fail("绝招用的太多太滥就不灵了。\n");
	message_vision(HIC"\n$N运足精神，一个高跳在空，使出了「乾坤一棒」的绝技！\n"NOR,me);

	me->delete("env/brief_message");
	target->delete("env/brief_message");

        me->set_temp("QJB_perform", 7);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->delete_temp("QJB_perform");

            me->receive_damage("sen", 100+random(100));      
                       me->add("force", -200);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

       me->start_busy(2);
   me->set_temp("fc_pfm_busy",1);
   me->set_temp("no_move",1);
  call_out("remove_effect",1+random(3),me);
  call_out("remove_no_move",1,me);
        return 1;
}

void remove_effect(object me) {
  if (me)  me->delete_temp("fc_pfm_busy");
}
void remove_no_move(object me) {
  if (me) me->delete_temp("no_move");
}
