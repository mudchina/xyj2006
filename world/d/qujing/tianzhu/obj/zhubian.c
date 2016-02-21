#include <weapon.h>

inherit WHIP;

void create()
{
  set_name("竹鞭",({ "zhu bian","zhubian", "bian", "whip" }) );
  set_weight(900);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "根");
    set("value", 100);
    set("material", "bamboo");
    set("long", "这是一根长长的竹鞭。\n");
    set("wield_msg", "$N拿出一把$n，捏在手中。\n");
    set("unequip_msg", "$N放下手中的$n。\n");
  }
  init_whip(10);
  setup();
}
