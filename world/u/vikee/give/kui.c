#include <armor.h>

inherit HEAD;

void create()
{
  set_name("铁盔", ({ "tie kui", "tiekui", "kui" }) );
  set_weight(2200);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "顶");
    set("long","一顶沉重的大铁盔，顶上有一尖柄。\n");
    set("value", 1000);
    set("material", "cloth");
    set("armor_prop/armor", 10);
    set("armor_prop/personality", 1);
	set("no_sell",1);
				set("no_drop","去垃圾堆丢吧，乱扔会污染环境!\n");
				set("no_give","总管发的装备，可不能乱送人哟！\n");
				set("no_get","想拿总管一叶知秋发的装备？做梦吧!\n");
  }
  setup();
}

