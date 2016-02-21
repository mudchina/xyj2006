//Cracked by Roath

#include <ansi.h>

inherit ITEM;

void create()
{
  set_name( HIM"百花酿"NOR , ({"baihua niang", "wine"}));
  set_weight(500);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "瓶");
    set("long","百花仙子采集各时仙花酿制的美酒。\n");
    set("value", 800000);
    set("no_sell", 1);
    set("drug_type", "补品");
  }
  setup();
  set("remaining",random(100)+1);
}


void init()
{
  add_action("do_drink", "drink");
  add_action("do_add","add");
}

int do_drink(string arg)
{
  int food,water;
  object me = this_player();
  int max=(int)me->query("max_mana")*2;
  int flowers=query("flowers");

  if (arg!="baihua niang" && arg!="wine") return 0;
  
  if (me->query("water")>me->max_water_capacity())
    return notify_fail("你再也喝不下了。\n");
  message_vision(HIG"$N端起百花酿喝了一口。\n"NOR,me);
  me->apply_condition("drunk", (int)me->query_condition("drunk")+1);
  add("remaining",-1);
  me->add("water",30);
  if (flowers) {
    if (flowers>5) flowers=5;
    message_vision(HIG"$N感到灵台清明无比，刹那间法力大涨。\n"NOR,me);
    me->add("mana",flowers*(80+random(40)));
    if (me->query("mana")>max) me->set("mana",max);
  }
  if (!query("remaining")) {
    message_vision("$N将一小瓶百花酿喝的精光，随手把酒瓶扔了。\n",me);
    destruct(this_object());
  }
  return 1;
}

int do_add(string arg) {
  object flower;  
  object me=this_player();
  if (!arg) return 0;
  if (!flower=present(arg,me)) return 0;
  if (flower->query("id")!="flower") return notify_fail("你不能往百花酿里丢这样东西！\n"); 

  if (flower->query("baihuaniang")) {
     message_vision(HIG"$N将一朵"+flower->query("name")+
       HIG"溶入百花酿中，花香酒香混作一处，满室芬芳，说不出的甜美。\n"NOR,me);
     add("flowers",1);
  } else message_vision(HIR"$N将"+flower->query("name")+
       HIR"揉碎，扔进百花酿中，花瓣点点，漂在酒中，给人以落花飘零之感。\n"NOR,me);
  destruct(flower);
  return 1;
}
