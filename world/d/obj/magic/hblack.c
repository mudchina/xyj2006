// created by snowcat
// 5/22/1997

#include <weapon.h>
#include <armor.h>
#include "hair.h"

inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("黑色毫毛", ({ "black hair", "blackhair", "hair" }) );
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long", "一把深黑色的毫毛，可以用来变成食物（transform）。\n");
    set("unit", "把");
    set("value",10000);
  }
  set("no_drop",1);
  set("no_get",1);
  set("no_sell",1);
  setup();
}

string name_suffix()
{
  string *strs = ({
    "饼",
    "糕",
    "肉",
    "菜",
    "饭",
  });
  return strs[random(sizeof(strs))];
}

string new_unit()
{
  return "碗";
}

int init ()  
{   
  add_action ("do_transform", "transform");
  add_action ("do_eat", "eat");
  return 1;
}

int do_eat (string arg)
{
  object me = this_player();
  object ob = this_object();

  if (!arg || present (arg,environment(ob))!=ob)
    return 0; // to invoke standard function
  if (!ob->query("has_transformed")) {
    tell_object (me,"请先将它变成你所需要的食物。\n");
    return 1;
  }
  me->set("food", (int)me->max_food_capacity());
  message_vision ("$N狼吞虎咽地把$n吃下去，满意地拍拍肚子。\n",me,ob);
  destruct(ob);
  return 1;
}

