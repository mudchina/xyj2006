// by snowcat 12/2/1997

#include <ansi.h>

inherit ITEM;

void create()
{
  set_name( "发霉的养身丹" , ({"yangshen dan", "dan"}));
  set_weight(120);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "颗");
    set("long", "一颗长霉的养身丹，上面全是绿毛。\n");
    set("value", 0);
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
  if (arg!="yangshen dan" && arg!="dan") 
    return 0;
  
  tell_object(me, "坏药还能吃吗？\n");
  return 1;
}

