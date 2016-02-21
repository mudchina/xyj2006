#include <weapon.h>

inherit STAFF;

void create()
{
  set_name("狮腿骨", ({ "shitui gu", "gu", "staff" }) );
  init_staff(20);
  set("unit", "根");
  set_weight(600);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 260);
    set("material", "metal");
  }
  set("wield_msg","$N操起$n握在手里。\n");
  setup();
}

