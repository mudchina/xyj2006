
#include <weapon.h>

inherit STAFF;

void create()
{
  set_name("蟠龙拐", ({"panlong guai", "guai", "staff"}));
  set_weight(1000);
  if( clonep() )
      set_default_object(__FILE__);
  else {
    set("unit", "根");
    set("value", 5000);
    set("material", "iron");
    set("long", "一根乌黑的蟠龙拐杖，上雕有龙头。\n");
    set("wield_msg", "$N举起一根$n，锵地一舞。\n");
    set("unequip_msg", "$N将$n锵地一声往地上一戳。\n");
  }
  init_staff(75);
  setup();
}

