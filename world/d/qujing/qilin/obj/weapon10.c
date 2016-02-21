#include <weapon.h>

inherit SWORD;

void create()
{
  set_name("象牙剑", ({ "xiangya jian", "jian", "sword" }) );
  init_sword(45);
  set("unit", "根");
  set_weight(1000);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 510);
    set("material", "bone");
  }
  set("wield_msg","$N操起$n握在手里。\n");
  setup();
}

