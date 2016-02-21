#include <weapon.h>

inherit STAFF;

void create()
{
  set_name("לרױָ", ({ "chan zhang", "zhang", "staff" }) );
  init_staff(35);
  set("unit", "¸ש");
  set_weight(1000);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 250);
    set("material", "metal");
  }
  setup();
}

