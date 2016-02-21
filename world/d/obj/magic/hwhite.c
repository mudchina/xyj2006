// created by snowcat
// 5/22/1997

#include <weapon.h>
#include <armor.h>
#include "hair.h"

inherit ITEM;
inherit F_LIQUID;

void create()
{
  set_name("白色毫毛", ({ "white hair", "whitehair", "hair" }) );
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long", "一把纯白色的毫毛，可以用来变成饮料（transform）。\n");
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
    "水",
    "汤",
    "酒",
    "汁",
    "露",
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
  add_action ("do_drink", "drink");
  return 1;
}

int do_drink (string arg)
{
  object me = this_player();
  object ob = this_object();

  if (!arg || present (arg,environment(ob))!=ob)
    return 0; // to invoke standard function
  if (!ob->query("has_transformed")) {
    tell_object (me,"请先将它变成你所需要的饮料。\n");
    return 1;
  }
  me->set("water", (int)me->max_water_capacity());
  message_vision ("$N拿起$n一口气喝了下去，满意地拍拍肚子。\n",me,ob);
  destruct(ob);
  return 1;
}

