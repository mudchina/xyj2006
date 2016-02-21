// by smile 12/08/1998
#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
  set_name("人皮", ({"renpi","cloth"}));
  set_weight(1000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "一张血淋淋的人皮。\n");
    set("material", "cloth");
    set("unit", "张");
    set("value", 1000);
    set("armor_prop/armor", 10);
  }
  setup();
}


