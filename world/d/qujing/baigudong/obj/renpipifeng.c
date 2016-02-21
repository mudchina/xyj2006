// by smile 12/08/1998
#include <ansi.h>
#include <armor.h>

inherit SURCOAT;

void create()
{
  set_name(HIY "人皮披风" NOR, ({"baigu pifeng", "pifeng"}));
  set_weight(4000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "一件血淋淋的人皮披风,隐隐的散发出一股血腥味。\n");
    set("material", "leather");
    set("unit", "件");
    set("value", 2000);
    set("armor_prop/armor", 50);
    set("armor_prop/courage",8);
  }
  setup();
}


