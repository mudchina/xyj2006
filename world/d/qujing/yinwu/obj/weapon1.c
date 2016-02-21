#include <weapon.h>

inherit STAFF;

void create()
{
  set_name("枯松杖", ({ "kusong zhang", "zhang", "staff" }) );
  init_staff(20);
  set("unit", "根");
  set_weight(550);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("value", 280);
    set("material", "metal");
  }
  set("wield_msg","$N操起$n握在手里。\n");
  setup();
}

