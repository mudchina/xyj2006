#include <weapon.h>

inherit BLADE;

void create()
{
  set_name("砍山刀", ({ "kanshan dao", "dao", "blade" }) );
  init_blade(35);
  set("unit", "把");
  set_weight(750);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 300);
    set("material", "metal");
  }
  set("wield_msg","$N操起$n握在手里。\n");
  setup();
}

