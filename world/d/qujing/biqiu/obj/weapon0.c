#include <weapon.h>

inherit STAFF;

void create()
{
  set_name("杨树桩", ({ "yangshu zhuang", "zhuang", "staff" }) );
  init_staff(16);
  set("unit", "根");
  set_weight(500);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 80);
    set("material", "wood");
  }
  set("wield_msg","$N操起$n握在手里。\n");
  setup();
}

