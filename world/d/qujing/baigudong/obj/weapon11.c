#include <weapon.h>

inherit SPEAR;

void create()
{
  set_name("¶Ï»êÇ¹", ({ "duanhun qiang", "qiang", "spear" }) );
  init_spear(40);
  set("unit", "¸ù");
  set_weight(1000);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 200);
    set("material", "iron");
  }
  setup();
}

