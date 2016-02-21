#include <weapon.h>

inherit AXE;

void create()
{
  set_name("鹰嘴斧", ({ "yingzui fu", "fu", "axe" }) );
  init_axe(28);
  set("unit", "柄");
  set_weight(1100);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 130);
    set("material", "metal");
  }
  set("wield_msg","$N操起$n握在手里。\n");
  setup();
}

