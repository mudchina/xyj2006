#include <weapon.h>
inherit MACE;

void create()
{
  set_name("短软狼牙棒", ({ "langya bang", "bang", "mace" }));
  set_weight(6000);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "根");
    set("long", "这是一根又短又软的狼牙棒，极为好使。\n");
    set("value", 500);
    set("material", "bronze");
    set("wield_msg", "$N嗖地舞起一根$n握在手中。\n");
    set("unwield_msg", "$N将手中的$n放下。\n");
  }
  init_mace(55);
  setup();
}

