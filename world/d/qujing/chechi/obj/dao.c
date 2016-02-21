// blade.c

#include <weapon.h>

inherit BLADE;

void create()
{
  set_name("斩头刀", ({"zhantou dao", "dao", "blade"}) );
  set_weight(4000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "柄");
    set("value", 500);
    set("material", "iron");
    set("long", "这是一柄大头厚刃的斩头刀。\n");
    set("wield_msg", "$N拔出一柄明晃晃的$n握在手中。\n");
    set("unequip_msg", "$N将手中的$n插入腰间的刀鞘。\n");
  }
  init_blade(35);
  setup();
}
