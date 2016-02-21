#include <weapon.h>

inherit WHIP;

void create()
{
  set_name("牛尾", ({ "niu wei", "wei", "whip" }) );
  init_whip(7);
  set("unit", "根");
  set_weight(200);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 110);
    set("material", "skin");
  }
  set("wield_msg","$N操起$n握在手里。\n");
  setup();
}

