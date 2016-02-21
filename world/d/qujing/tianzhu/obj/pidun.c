#include <armor.h>

inherit CLOTH;

void create()
{
  set_name("ºñÅ£Æ¤¶Ü", ({"houniu pidun", "pidun", "dun"}));
  set_weight(4500);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "¼þ");
    set("value", 2000);
    set("material", "leather");
    set("armor_prop/armor", 20);
  }
  setup();
}

