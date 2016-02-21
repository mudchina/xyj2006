#include <weapon.h>

inherit FORK;

void create()
{
  set_name("龙须叉", ({ "longxu cha", "cha", "fork" }) );
  init_fork(45);
  set("unit", "根");
  set_weight(900);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 480);
    set("material", "bone");
  }
  set("wield_msg","$N操起$n握在手里。\n");
  setup();
}

