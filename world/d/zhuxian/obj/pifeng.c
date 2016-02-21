// by snowcat oct 15 1997
#include <ansi.h>

#include <armor.h>

inherit SURCOAT;

void create()
{
  set_name(HIG "仙灵披风" NOR, ({"xianling pifeng", "pifeng", "cloth"}));
  set_weight(4500);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "一件披风。\n");
    set("material", "leather");
    set("unit", "件");
    set("value", 700);
    set("armor_prop/armor", 35);
    set("armor_prop/armor_vs_force", 300);
  }
  setup();
}


