#include <weapon.h>

inherit BLADE;

void create()
{
  set_name("虎头刀", ({ "hutou dao", "dao", "blade" }) );
  init_blade(38);
  set("unit", "把");
  set_weight(800);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 390);
    set("material", "bone");
  }
  set("wield_msg","$N操起$n握在手里。\n");
  setup();
}

