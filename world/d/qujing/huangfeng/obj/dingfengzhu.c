// created by wxb 12/24/1998
// room: /d/qujing/huangfeng/obj/dingfengzhu.c

#include <ansi.h>
inherit ITEM;
inherit F_UNIQUE;

void create()
{
  set_name(HIC "定风珠" NOR, ({ "dingfeng zhu","zhu" }));
  set_weight(500);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long", "一颗淡青色的珠子，里面似乎有光影流动. \n");
    set("unit", "颗");
    set("material", "gold");
    set("no_get",1);
    set("no_give","这是宝物，岂可随便给人？\n");
    set("no_sell",1);
    set("no_put","这颗珠子放不进去。\n");
    set("is_monitored",1);
    set("replace_file","/d/qujing/huangfeng/obj/fake-zhu");
  }
    setup();
}
