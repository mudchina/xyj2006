#include <weapon.h>

inherit STAFF;

void create()
{
  set_name("Ñ¹Æ¤ÕÈ", ({ "huntie zhang", "zhang", "staff" }) );
  init_staff(35);
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

