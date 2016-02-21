// by snowcat 12/2/1997

#include <ansi.h>

inherit ITEM;

void create()
{
  set_name( YEL"无花果"NOR, ({"wuhua guo", "guo"}));
  set_weight(120);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "颗");
    set("long", "听说常吃无花果可以长生不老。\n");
    set("value", 1000);
    set("no_sell", 1);
    set("drug_type", "补品");
  }
  setup();
}

void init()
{
  add_action("do_eat", "eat");
}

int do_eat(string arg)
{
  object me = this_player();
  if (arg!="wuhua guo" && arg!="guo") 
      return notify_fail("你要吃什么？\n");
  
//  if (me->query("family/family_name") != "盘丝洞" ) return notify_fail("你不是盘丝门下，这果子可吃不得！\n");
  
  me->set("food", (int)me->max_food_capacity()*3+random(100));
  me->set("water", (int)me->max_water_capacity()*3+random(100));
  message_vision(HIG "$N掰开一枚无花果往嘴里一放。\n" NOR, me);
  tell_object(me, "顿时你觉得口中生津，一股仙气自上而下如醍醐灌顶。\n");
  destruct(this_object());
  return 1;
}
