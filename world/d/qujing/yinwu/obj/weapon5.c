#include <weapon.h>

inherit WHIP;

void create()
{
  set_name("鹿皮鞭", ({ "lupi bian", "bian", "whip" }) );
  init_whip(20);
  set("unit", "根");
  set_weight(1000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("value", 280);
    set("material", "skin");
  }
  set("wield_msg","$N操起$n握在手里。\n");
  setup();
}

