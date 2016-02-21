#include <weapon.h>

inherit SPEAR;

void create()
{
  set_name("荜萝枪", ({ "biluo qiang", "qiang", "spear" }) );
  init_spear(40);
  set("unit", "根");
  set_weight(1000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("value", 450);
    set("material", "metal");
  }
  set("wield_msg","$N操起$n握在手里。\n");
  setup();
}

