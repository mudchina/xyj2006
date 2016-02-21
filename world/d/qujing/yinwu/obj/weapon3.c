#include <weapon.h>

inherit FORK;

void create()
{
  set_name("槐刺叉", ({ "huaici cha", "cha", "fork" }) );
  init_fork(20);
  set("unit", "根");
  set_weight(500);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("value", 180);
    set("material", "metal");
  }
  set("wield_msg","$N操起$n握在手里。\n");
  setup();
}

