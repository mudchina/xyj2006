// rake.c

#include <weapon.h>

inherit F_UNIQUE; 
inherit RAKE;

void create()
{
  set_name("小九齿钯", ({ "xiao jiuchi pa", "jiuchipa", "pa","rake" }) );
  set_weight(10000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "柄");
    set("value", 2000);
    set("material", "iron");
    set("no_sell", 1);
    set("no_drop", 1);
    set("is_monitored", 1);
    set("replace_file", "/d/obj/weapon/rake/gangpa");
    set("long", "一柄九齿钯，佩有银纹长把。\n");
    set("wield_msg", "$N抄起一柄$n，往空中顺手一筑。\n");
    set("unwield_msg", "$N放下$n，往身后一拖。\n");
  }
  init_rake(65);
  setup();
}

void destruct_me(object where, object me)
{
  message_vision("一道紫气闪过，$n被突如其来的霞光收走了！\n",where,me);
  destruct (me);
}

void init()
{
  object me = this_object();
  object where = environment();

  ::init();
  if (interactive(where))
  {
    if (me->query("owned"))
    {
      if (me->query("owned")!=where->query("id"))
      {
        call_out("destruct_me",1,where,me);
      }
    }
    else
    {
      me->set("owned",where->query("id"));
    }
  }
}

