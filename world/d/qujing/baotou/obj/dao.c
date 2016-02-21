// blade.c

#include <weapon.h>

inherit BLADE;

void create()
{
  set_name("太乙竹刀", ({"taiyi zhu dao", "zhu dao", "dao"}) );
  set_weight(1000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "柄");
    set("value", 2000);
    set("material", "bamboo");
    set("no_sell", 1);
    set("no_drop", 1);
    set("is_monitored", 1);
    set("replace_file", "/d/obj/weapon/blade/blade");
    set("long", "这是一柄细竹刀，上有护道神符。\n");
    set("wield_msg", "$N抽出一柄细细的$n握在手中，霓光闪烁。\n");
    set("unequip_msg", "霓光一闪，$N将手中的$n收起。\n");
  }
  init_blade(65);
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

