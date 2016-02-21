//Cracked by Roath

#include <weapon.h>

inherit MACE;

void create()
{
  set_name("乌凤锏", ({ "wufeng jian", "jian", "mace" }) );
  set_weight(7000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "根");
    set("value", 1000);
    set("material", "steal");
    set("long", "一根深黛色凤翎玉柄乌凤锏。\n");
    set("wield_msg", "$N握起$n，大喝了一声：好锏。\n");
  }
  init_mace(65);
  setup();
}

