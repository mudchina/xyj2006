#include <weapon.h>

inherit SWORD;

void create()
{
  set_name("雉尾剑", ({ "zhiwei jian", "jian", "sword" }) );
  init_sword(36);
  set("unit", "把");
  set_weight(700);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("value", 370);
    set("material", "metal");
  }
  set("wield_msg","$N操起$n握在手里。\n");
  setup();
}

