#include <weapon.h>

inherit WHIP;

void create()
{
  set_name("凤尾鞭", ({ "fengwei bian", "bian", "whip" }) );
  init_whip(35);
  set("unit", "根");
  set_weight(700);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 410);
    set("material", "bone");
  }
  set("wield_msg","$N操起$n握在手里。\n");
  setup();
}

