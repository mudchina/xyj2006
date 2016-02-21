#include <weapon.h>

inherit BLADE;

void create()
{
  set_name("新月刀", ({ "xinyue dao", "dao", "blade" }) );
  init_blade(30);
  set("unit", "把");
  set_weight(1000);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 390);
    set("material", "metal");
  }
  set("wield_msg","$N操起$n握在手里。\n");
  setup();
}

