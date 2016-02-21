// by snowcat oct 15 1997
#include <armor.h>

inherit CLOTH;

void create()
{
  set_name("战袍", ({"zhan pao", "cloth"}));
  set_weight(4000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "一件战袍。\n");
    set("material", "cloth");
    set("unit", "件");
    set("value", 600);
    set("armor_prop/armor", 30);
	set("no_sell",1);
				set("no_drop","去垃圾堆丢吧，乱扔会污染环境!\n");
				set("no_give","总管发的装备，可不能乱送人哟！\n");
				set("no_get","想拿总管一叶知秋发的装备？做梦吧!\n");
  }
  setup();
}

