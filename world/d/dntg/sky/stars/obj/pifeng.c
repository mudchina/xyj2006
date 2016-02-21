// by snowcat oct 15 1997
#include <armor.h>

inherit SURCOAT;

void create()
{
  set_name("披风", ({"pifeng"}));
  set_weight(4500);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "一件披风。\n");
    set("material", "leather");
    set("unit", "件");
    set("value", 700);
    set("armor_prop/armor", 35);
  }
  setup();
}


