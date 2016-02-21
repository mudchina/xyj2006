// by snowcat oct 15 1997
#include <armor.h>

inherit CLOTH;

void create()
{
  set_name("皇袍", ({"huang pao", "cloth"}));
  set_weight(4000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "一件缀满珍珠宝石的皇袍。\n");
    set("material", "cloth");
    set("unit", "件");
    set("value", 20000);
    set("armor_prop/armor", 30);
  }
  setup();
}

