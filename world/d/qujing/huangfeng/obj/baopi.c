// created by wxb 12/24/1998
// room: /d/qujing/huangfeng/obj/baopi.c

#include <armor.h>

inherit CLOTH;

void create()
{
  set_name("豹皮", ({"bao pi", "pi"}));
  set_weight(4500);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "一张豹子皮，上有金钱花纹。\n");
    set("material", "leather");
    set("unit", "张");
    set("armor_prop/armor", 15);
  }
  setup();
}

