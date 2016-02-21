// by snowcat oct 15 1997
#include <armor.h>

inherit CLOTH;

void create()
{
  set_name("浴巾", ({"yu jin", "yujin", "jin"}));
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "一条长长的粗布宽浴巾。\n");
    set("wear_msg", "$N将浴巾展开，仔细地裹在身上。\n");
    set("material", "cloth");
    set("unit", "条");
    set("value", 110);
    set("armor_prop/armor", 4);
  }
  setup();
}

