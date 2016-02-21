#include <armor.h>

inherit CLOTH;

void create()
{
  set_name("大花袍", ({"hua pao", "pao"}));
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long","一件印着大花的棉丝袍，宽大舒适。\n");
    set("material", "cloth");
    set("unit", "件");
    set("value", 500);
    set("armor_prop/armor", 5);
    set("armor_prop/personality", 1);
  }
  setup();
}

