#include <armor.h>

inherit CLOTH;

void create()
{
  set_name("官袍", ({"guan pao", "pao"}));
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long","一件绣着花纹的棉丝官袍。\n");
    set("material", "cloth");
    set("unit", "件");
    set("value", 400);
    set("armor_prop/armor", 5);
    set("armor_prop/personality", 1);
  }
  setup();
}

