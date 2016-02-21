// created by wxb 12/24/1998
// room: /d/qujing/huangfeng/obj/hupi.c

#include <armor.h>

inherit CLOTH;

void create()
{
  set_name("虎皮", ({"hu pi", "pi"}));
  set_weight(4500);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "一张老虎皮，毛色黯淡，看起来有点旧。\n");
    set("material", "leather");
    set("unit", "张");
    set("armor_prop/armor", 15);
  }
  setup();
}

