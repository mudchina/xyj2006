#include <weapon.h>

inherit STICK;

void create()
{
  set_name("杨树拐", ({ "yangshu guai", "guai", "stick" }) );
  init_stick(20);
  set("unit", "根");
  set_weight(500);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 90);
    set("material", "wood");
  }
  set("wield_msg","$N操起$n握在手里。\n");
  setup();
}

