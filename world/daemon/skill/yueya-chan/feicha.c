
#include <ansi.h>
#include <combat.h>

inherit SSERVER;

void feicha_ok(object);
void postfeicha(object,object,object,int);

int perform(object me, object target)
{
    mapping feicha= ([
       "damage": 80,
       "dodge" : -10,
       "parry" : -10,
       "damage_type" : "刺伤",
//       "action" :  HIC"$N突然清啸一声，掌中$w"+HIC"脱手而出,直向$n的$l飞去,这正是[飞叉绝艺]!"NOR,
               "action" :  HIC"$w"+HIC"遇力而发，向$n的$l扑去",
             "post_action" : (: postfeicha :)
    ]);

      object weapon=me->query_temp("weapon");
      if( !target ) target = offensive_target(me);
      if( !target || !target->is_character()||target->is_corpse()||target==me)
          return notify_fail("你要对谁使用[飞叉绝艺]？\n");
      if (!target->is_fighting(me))
             return notify_fail("你们没有在打架！\n");
      if (me->query_temp("no_feicha") )
          return notify_fail("你现在状态不佳，不能使用飞叉绝艺。\n");      
      if (me->query_skill("huaxue-force",1)<70)
          return notify_fail("你的内功差。\n");
      if (me->query_skill("yueya-chan",1)<70) 
          return notify_fail("你的月牙铲还不够火候。\n");
         if (me->query("force")<100)
           return notify_fail("你内力不继，难以使用飞叉绝艺。\n");
     
      me->add("force", -100);
      me->set("actions",feicha);
    message_vision(HIC"$N突然清啸一声，手中"+weapon->query("name")+HIC"脱手而出，直向$n飞去！这正是[飞叉绝艺]!"NOR,me,target);
      COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
      me->set_temp("no_feicha",1);
      call_out("feicha_ok",2+random(2),me);
      me->reset_action();
      return 1;
}

void feicha_ok(object me) {
      if (!me) return;
      me->delete_temp("no_feicha");
}         

void postfeicha(object me,object victim,object weapon, int damage) {
      if (damage>0 || damage==RESULT_DODGE)
         message_vision(HIC""+weapon->query("name")+HIC"失去化血神功的功力又飞回到$N手中。\n"NOR,me);
      else {
           message_vision(HIC""+weapon->query("name")+HIC"无法受到化血神功的支配,掉在地上。\n"NOR,me);
           weapon->move(environment(me));
      }
}
