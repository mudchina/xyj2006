// created by snowcat
// 5/22/1997

#include <weapon.h>
#include <armor.h>
#include "hair.h"

inherit MACE;

void create()
{
  set_name("靛色毫毛", ({ "indigo hair", "indigohair", "hair" }) );
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long", "一把蓝靛色的毫毛，可以用来变成锏类武器（transform）。\n");
    set("unit", "把");
    set("value",10000);
  }
  set("no_drop",1);
  set("no_get",1);
  set("no_sell",1);
  init_mace(10+random(20));
  setup();
}

string name_suffix()
{
  return "锏";
}

string new_unit()
{
  return "把";
}

int init ()  
{   
  add_action ("do_transform", "transform");
  add_action ("do_wield", "wield");
  return 1;
}

int do_wield (string arg)
{
  object me = this_player();
  object ob = this_object();

  if (!arg || present (arg,environment(ob))!=ob)
    return 0; // to invoke standard function
  if (!ob->query("has_transformed")) {
    tell_object (me,"请先将它变成你所需要的武器。\n");
    return 1;
  }
  return 0; // to invoke standard function
}

