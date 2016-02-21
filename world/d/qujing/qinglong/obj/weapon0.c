#include <weapon.h>

inherit SWORD;

void create()
{
  set_name("棠花剑", ({ "tanghua jian", "jian", "sword" }) );
  init_sword(35);
  set("unit", "把");
  set_weight(750);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 310);
    set("material", "metal");
  }
  set("wield_msg","$N操起$n握在手里。\n");
  setup();
}

