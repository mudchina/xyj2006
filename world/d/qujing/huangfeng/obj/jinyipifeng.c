// by smile 12/13/1998

#include <ansi.h>
#include <armor.h>

inherit SURCOAT;

void create()
{
  set_name(HIY "锦衣披风" NOR, ({"jinyi pifeng", "pifeng"}));
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "一件锦缎所制的披风。\n");
    set("material", "leather");
    set("unit", "件");
    set("value", 12500);
    set("armor_prop/armor", 60);
  }
  setup();
}


