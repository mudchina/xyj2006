#include <weapon.h>

inherit STICK;

void create()
{
  set_name("鸳鸯棍", ({ "yuanyang gun", "gun", "stick" }) );
  init_stick(40);
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

