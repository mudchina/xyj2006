
#include <weapon.h>

inherit F_UNIQUE; 
inherit STAFF;

void create()
{
  set_name("小降妖杖", ({"xiao xiangyao zhang", "xiangyaozhang", "zhang", "staff"}));
  set_weight(10000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "杆");
    set("value", 2000);
    set("material", "iron");
    set("no_sell", 1);
    set("no_drop", 1);
    set("is_monitored", 1);
    set("replace_file", "/d/obj/weapon/staff/gangzhang");
    set("long", "这是一杆乌铁降妖杖，两头为银铸成。\n");
    set("wield_msg", "$N反手抽出一杆$n，在手中锵地一抡。\n");
    set("unequip_msg", "$N将手中的$n锵地放下。\n");
  }
  init_staff(65);
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

