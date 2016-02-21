// created by wxb 12/24/1998
// room: /d/qujing/huangfeng/obj/cha.c

#include <weapon.h>

inherit FORK;

void create()
{
  set_name("三股钢叉", ({ "sangu gangcha", "gangcha", "cha","fork" }) );
  set_weight(8000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "柄");
    set("value", 1000);
    set("material", "steal");
    set("long", "一柄锋利锃亮的三股钢叉。\n");
    set("wield_msg", "$N身子一抖，飞手抄起一柄$n。\n");
  }
  init_fork(65);
  setup();
}

