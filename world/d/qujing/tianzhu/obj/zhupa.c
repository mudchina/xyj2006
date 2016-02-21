#include <weapon.h>

inherit RAKE;

void create()
{
  set_name("竹耙",({ "zhu pa","zhupa", "pa", "rake" }) );
  set_weight(900);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "把");
    set("value", 100);
    set("material", "bamboo");
    set("long", "这是一把长长的竹耙。\n");
    set("wield_msg", "$N拿出一把$n，举在手中。\n");
    set("unequip_msg", "$N放下手中的$n。\n");
  }
  init_rake(10);
  setup();
}
