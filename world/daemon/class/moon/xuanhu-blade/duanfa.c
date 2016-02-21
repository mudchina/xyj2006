#include <ansi.h>
#include <combat.h>
inherit SSERVER;

void duanfa_ok(object);

int perform(object me, object target)
{
        int damage;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展这一招「短发」？\n");
		if(me->query("family/family_name") != "月宫")
                return notify_fail("[短发]是月宫不传之密！\n");
        if(!me->is_fighting())
                return notify_fail("「短发」只能在战斗中使用！\n");
        if((int)me->query("max_force") < 300 )
                return notify_fail("你的内力不够！\n");
          if((int)me->query("force") < 300 )
                return notify_fail("你的内力不足！\n");
        if((int)me->query("sen") < 100 )
                return notify_fail("你的精神不足，没法子施用外功！\n");
        if((int)me->query_skill("xuanhu-blade", 1) < 100)
                return notify_fail("你的玄狐长恨刀法不够熟练，使用这一招会有困难！\n");
         if(me->query_temp("no_duanfa"))
                        return notify_fail("看你香汗淋漓的样子，等会儿再用吧！\n");
        me->delete("env/brief_message");
        target->delete("env/brief_message");
message_vision(HIW"\n$N手中刀势一缓，和着刀声唱起歌来！~~~\n"NOR,me,target);
message_vision(HIC"\n我已剪短了我的发，剪断了牵挂……\n"NOR,me,target);
message_vision(HIC"\n一刀两断，你的情话，你的慌话……\n"NOR,me,target);
              damage=(int)me->query_skill("blade")+random((int)me->query_skill("blade"));
              if (random((int)target->query("combat_exp"))<(int)me->query("combat_exp")/2)
{
              message_vision(HIW"\n$n听着听着不由心底一酸，心神荡漾，三魂六魄都丢光了\n"NOR,me,target);
             target->receive_damage("sen",damage);
              target->receive_wound("sen",damage/2);
             COMBAT_D->report_status(target);
}
else {
             message_vision(HIG"\n$n冷哼一声，五音不全，跑调了都不知道？\n"NOR,me,target);
             }
        me->receive_damage("sen", 50);
        me->add("force", -100);
        me->set_temp("no_duanfa",1);
                call_out("duanfa_ok",1+random(2),me);
        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
}
}
return 1;
}

void duanfa_ok(object me)
{
if (!me) return;
      me->delete_temp("no_duanfa");
}
