// created by wxb 12/24/1998
// room: /d/qujing/huangfeng/obj/fake-zhu.c

#include <ansi.h>

inherit ITEM;

void create()
{
  set_name(HIC"夜明珠"NOR, ({ "yeming zhu","zhu" }));
  set_weight(500);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long", "一颗可以夜间发光的珠子，据说价值连城！\n");
    set("unit", "颗");
    set("material", "gold");
    set("value", 60000);
  }
  setup();
}
