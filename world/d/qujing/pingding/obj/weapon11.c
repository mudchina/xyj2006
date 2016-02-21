#include <weapon.h>

inherit SPEAR;

void create()
{
  set_name("ºìÓ§Ç¹", ({ "hongying qiang", "qiang", "spear" }) );
  init_spear(35);
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

