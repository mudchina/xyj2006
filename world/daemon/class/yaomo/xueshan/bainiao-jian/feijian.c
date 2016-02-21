
#include <ansi.h>
#include <combat.h>

inherit SSERVER;

void feijian_ok(object);
void postfeijian(object,object,object,int);

int perform(object me, object target)
{
    mapping feijian= ([
       "damage": 180,
       "dodge" : -60,
       "parry" : -60,
       "damage_type" : "刺伤",
//       "action" :  HIW"$N突然清啸一声，掌中$w"+HIW"脱手而出，化做一道长虹，直向$n的$l飞去！"NOR,
       "action" :  HIW"$w"+HIW"在空中幻出道道剑光，飞鸟投林般，向$n的$l扑去",
       "post_action" : (: postfeijian :)
    ]);

      object weapon=me->query_temp("weapon");
      if(me->query("family/family_name")!="大雪山")
          return notify_fail("[飞鸟投林]只有雪山弟子才可以用！\n");
      if( !target ) target = offensive_target(me);
      if( !target || !target->is_character()||target->is_corpse()||target==me)
          return notify_fail("你要攻击谁？\n");
      if (!target->is_fighting(me))
             return notify_fail("你们没有在打架！\n");
      if (me->query_temp("no_feijian") )
          return notify_fail("你现在状态不佳，不能使用飞剑。\n");      
      if (me->query_skill("ningxie-force",1)<50)
          return notify_fail("你的内功太差，剑飞出去肯定飞不回来。\n");
      if (me->query_skill("bainiao-jian",1)<50) 
          return notify_fail("你的百鸟剑法那么烂，当心把剑插自己身上。\n");
    if (me->query_skill("throwing",1)<50)
        return notify_fail("你的暗器功夫太差，胡乱把剑扔出去，肯定找不到目标。\n");
      if (me->query("force")<100)
           return notify_fail("你内力不继，难以驾御飞剑。\n");
     
      me->add("force", -100);
      me->set("actions",feijian);
    message_vision(HIW"$N突然清啸一声，掌中"+weapon->query("name")+HIW"脱手而出，化做一道长虹，直向$n飞去！"NOR,me,target);
      COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
      me->set_temp("no_feijian",1);
      call_out("feijian_ok",2+random(2),me);
      me->reset_action();
      return 1;
}

void feijian_ok(object me) {
      if (!me) return;
      me->delete_temp("no_feijian");
}         

void postfeijian(object me,object victim,object weapon, int damage) {
      if (damage>0 || damage==RESULT_DODGE)
         message_vision(HIW""+weapon->query("name")+HIW"在空中打了个转，又飞回到$N手中。\n"NOR,me);
      else {
           message_vision(HIW""+weapon->query("name")+HIW"改变方向，“唰”的一声，斜斜插在地上。\n"NOR,me);
           weapon->move(environment(me));
      }
}
