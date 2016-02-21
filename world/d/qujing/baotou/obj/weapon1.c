#include <weapon.h>

inherit HAMMER;

void create()
{
  set_name("磬石锤", ({ "qingshi chui", "chui", "hammer" }) );
  init_hammer(24);
  set("unit", "把");
  set_weight(1200);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 130);
    set("material", "metal");
  }
  set("wield_msg","$N操起$n握在手里。\n");
  setup();
}

