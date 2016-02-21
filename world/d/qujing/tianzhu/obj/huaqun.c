#include <armor.h>

inherit CLOTH;

void create()
{
  set_name("水印花裙", ({ "hua qun", "qun", "skirt" }) );
  set_weight(2700);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long", "一条淡色水印花裙。\n");
    set("unit", "条");
    set("value", 500);
    set("material", "cloth");
    set("female_only", 1);
    set("armor_prop/armor", 1);
    set("armor_prop/dodge", 1);
  }
  setup();
}

