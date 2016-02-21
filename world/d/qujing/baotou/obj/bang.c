
#include <ansi.h>
#include <weapon.h>

inherit F_UNIQUE; 
inherit STICK;

void create()
{
  set_name("小金箍棒", ({ "xiao jingu bang", "jingubang", "bang", "stick" }) );
  set_weight(10000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "条");
    set("value", 2000);
    set("material", "iron");
    set("no_sell", 1);
    set("no_drop", 1);
    set("is_monitored", 1);
    set("replace_file", "/d/obj/weapon/stick/bintiegun");
    set("long", "此棒以银为箍，中间乃一段乌铁。上铸小字：“小金箍棒”。\n");
    set("wield_msg", "$N拿起$n，迎风一晃。\n");
    set("unwield_msg", "$N收起$n，$n顿时一闪不见了。\n");
  }
  init_stick(65);
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

