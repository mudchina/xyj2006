// by snowcat oct 29 1997
#include <weapon.h>

inherit HAMMER;
inherit F_FOOD;

void create()
{
  set_name("白鹿头", ({"bai lutou", "lutou"}));
  set_weight(1000);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "一只白色鹿头。\n");
    set("unit", "只");
    set("value", 1000);
    set("food_remaining", 6);
    set("food_supply", 40);
    set("wield_msg", "$N抓起一只$n当武器。\n");
    set("material", "bone");
  }
  init_hammer(1);
  setup();
}

int finish_eat()
{
  if( !query("weapon_prop") )
    return 0;
  set_name("啃得光光的鹿头", ({ "bone" }) );
  set_weight(200);
  set("long", "一只啃得光光的鹿头。\n");
  return 1;
}
