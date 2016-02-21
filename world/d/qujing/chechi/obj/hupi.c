// by snowcat oct 29 1997
#include <armor.h>

inherit CLOTH;

void create()
{
  set_name("黄虎皮", ({"huang hupi", "hupi"}));
  set_weight(4500);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "一张黄色虎皮。\n");
    set("material", "leather");
    set("unit", "张");
    set("value", 1000);
    set("armor_prop/armor", 15);
  }
  setup();
}

