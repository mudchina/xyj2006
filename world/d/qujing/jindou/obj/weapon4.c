#include <weapon.h>

inherit HAMMER;

void create()
{
  set_name("铁球", ({ "tie qiu", "qiu", "hammer" }) );
  init_hammer(38);
  set("unit", "柄");
  set_weight(1300);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 380);
    set("material", "iron");
  }
  set("wield_msg","$N拿起$n握在手里。\n");
  setup();
}

