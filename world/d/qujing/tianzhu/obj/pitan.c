#include <armor.h>

inherit SURCOAT;

void create()
{
  set_name("披毯", ({ "pi tan", "pitan", "tan" }) );
  set_weight(800);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "块");
    set("long", "一块布披毯，可以披在身上。\n");
    set("value", 130);
    set("material", "cloth");
    set("armor_prop/armor", 1);
    set("armor_prop/personality", 1);
  }
  setup();
}

