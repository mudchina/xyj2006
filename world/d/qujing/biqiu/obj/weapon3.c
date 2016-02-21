#include <weapon.h>

inherit WHIP;

void create()
{
  set_name("柳条鞭", ({ "liutiao bian", "bian", "whip" }) );
  init_whip(18);
  set("unit", "根");
  set_weight(400);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 75);
    set("material", "wood");
  }
  set("wield_msg","$N操起$n握在手里。\n");
  setup();
}

