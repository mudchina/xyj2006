#include <weapon.h>

inherit MACE;

void create()
{
  set_name("铁荆棘", ({ "tie jingji", "jingji", "mace" }) );
  init_mace(35);
  set("unit", "柄");
  set_weight(900);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 400);
    set("material", "iron");
  }
  set("wield_msg","$N拿起$n握在手里。\n");
  setup();
}

