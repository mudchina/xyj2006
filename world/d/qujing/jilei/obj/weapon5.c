//Cracked by Roath
#include <weapon.h>

inherit STAFF;

void create()
{
  set_name("Å£ÍÈÕÈ", ({ "niutui zhang", "zhang", "staff" }) );
  init_staff(35);
  set("unit", "¸ù");
  set_weight(500);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 410);
    set("material", "bone");
  }
  setup();
}

