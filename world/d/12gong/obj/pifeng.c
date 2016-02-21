#include <ansi.h>
#include <armor.h>

inherit F_UNIQUE;
inherit SURCOAT;

void create()
{
  set_name(HIM"圣羽披风"NOR, ({"shengyu pifeng", "pifeng", "cloth" }));
  set_weight(4500);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "一件集天地之灵气所造就的披风。\n");
    set("no_sell", 1);
    set("no_drop", 1);
    set("no_put", 1);
    set("material", "crimsonsteel");
    set("unit", "件");
    set("value", 1000);
    		set("replace_file", "/d/obj/cloth/hufa-jiasha");

	set("armor_prop/armor", 100);
//    set("armor_prop/dodge", 50);
//    set("armor_prop/spells", 30);
  }
  setup();
}


