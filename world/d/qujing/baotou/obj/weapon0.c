#include <weapon.h>

inherit DAGGER;

void create()
{
  set_name("单刃匕", ({ "danren bi", "bi", "dagger" }) );
  init_dagger(15);
  set("unit", "把");
  set_weight(600);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 120);
    set("material", "metal");
  }
  set("wield_msg","$N操起$n握在手里。\n");
  setup();
}

