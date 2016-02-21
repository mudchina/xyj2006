// by snowcat oct 15 1997
#include <armor.h>

inherit CLOTH;

void create()
{
  set_name("彩色披毯", ({"caise pitan", "caisepitan", "pitan"}));
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "一件彩色披毯。\n");
    set("material", "cloth");
    set("unit", "件");
    set("value", 400);
    set("armor_prop/armor", 15);
  }
  setup();
}

