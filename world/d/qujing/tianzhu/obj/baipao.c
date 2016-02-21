#include <armor.h>

inherit CLOTH;

void create()
{
  set_name("白袍", ({"bai pao", "pao"}));
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long","一件白色的棉丝袍，宽大舒适。\n");
    set("material", "cloth");
    set("unit", "件");
    set("value", 200);
    set("armor_prop/armor", 4);
  }
  setup();
}

