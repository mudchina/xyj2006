#include <armor.h>

inherit BOOTS;

void create()
{
  set_name( "登山屐", ({ "dengshan ji", "ji" }) );
  set_weight(1000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "双");
    set("long", "一双舒适的登山屐。\n");
    set("value", 80);
    set("material", "boots");
    set("armor_prop/dodge", 2);
  }
  setup();
}

