#include <armor.h>

inherit HEAD;

void create()
{
  set_name("布头巾", ({ "tou jin", "toujin", "jin" }) );
  set_weight(700);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "块");
    set("long", "一块大的布头巾。\n");
    set("value", 80);
    set("material", "cloth");
    set("armor_prop/armor", 1);
    set("armor_prop/personality", 1);
  }
  setup();
}

