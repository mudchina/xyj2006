// by snowcat oct 25 1997

#include <armor.h>
inherit CLOTH;

void create()
{
  set_name("宫袍", ({ "gong pao", "pao" }) );
  set_weight(2700);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long", "一件长袍．\n");
    set("unit", "件");
    set("value", 1000);
    set("material", "cloth");
    set("armor_prop/armor", 5);
    set("armor_prop/dodge", 10);
  }
  setup();
}

