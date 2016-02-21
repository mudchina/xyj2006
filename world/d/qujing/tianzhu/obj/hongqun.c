#include <armor.h>

inherit CLOTH;

void create()
{
  set_name("翡红裙", ({ "hong qun", "qun", "skirt" }) );
  set_weight(2700);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long", "一条翡红色长裙，配着小金穗。\n");
    set("unit", "条");
    set("value", 2000);
    set("material", "cloth");
    set("female_only", 1);
    set("armor_prop/armor", 5);
    set("armor_prop/dodge", 5);
  }
  setup();
}

