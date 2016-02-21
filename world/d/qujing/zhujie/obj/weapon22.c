#include <weapon.h>

inherit SWORD;

void create()
{
  set_name("葛剑", ({ "ge jian", "jian", "sword" }) );
  init_sword(25);
  set("unit", "把");
  set_weight(1000);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 280);
    set("material", "wood");
  }
  set("wield_msg","$N操起$n握在手里。\n");
  setup();
}

