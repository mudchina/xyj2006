// by snowcat 12/2/1997

#include <ansi.h>

inherit ITEM;

void create()
{
  set_name( "野参果" , ({"yeshen guo", "guo"}));
  set_weight(120);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "个");
    set("long", "一个神奇的野参果。\n");
    set("value", 1000000);
    set("drug_type", "补品");
  }
  set("no_give","野参果不能给人。\n");
  set("no_drop","野参果不能乱丢。\n");
  set("no_get","野参果不是你的吧。\n");
  set("is_monitored",1);
  setup();
}

void init()
{
  add_action("do_eat", "eat");
}

int do_eat(string arg)
{
  object me = this_player();
  if (arg!="yeshen guo" && arg!="guo") 
    return 0;
  
  me->set("eff_sen", (int)me->query("max_sen"));
  me->set("sen", (int)me->query("max_sen"));
  me->set("eff_gin", (int)me->query("max_gin"));
  me->set("gin", (int)me->query("max_gin"));
  me->set("eff_kee", (int)me->query("max_kee"));
  me->set("kee", (int)me->query("max_kee"));
  me->set("mana", (int)me->query("max_mana"));
  me->set("force", (int)me->query("max_force"));
  me->set("food", (int)me->max_food_capacity());
  me->set("water", (int)me->max_water_capacity());
  me->start_busy (10);
  message_vision(HIG "$N抓出野参果往嘴巴里一塞！\n\n" NOR, me);
  tell_object(me, "一股仙力慢慢从体内弥散开来……\n\n");
  destruct(this_object());
  return 1;
}

