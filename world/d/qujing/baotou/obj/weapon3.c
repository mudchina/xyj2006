#include <weapon.h>

inherit WHIP;

void create()
{
  set_name("百节链", ({ "baijie lian", "lian", "whip" }) );
  init_whip(26);
  set_weight(900);
  set("unit", "根");
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 140);
    set("material", "metal");
  }
  set("wield_msg","$N操起$n握在手里。\n");
  setup();
}

