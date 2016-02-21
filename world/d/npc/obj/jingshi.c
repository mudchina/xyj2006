# include <skill.h>
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(WHT"晶石"NOR, ({"jing shi", "shi"}));
	set_weight(500);
	if( clonep() )
    		set_default_object(__FILE__);
  	else {
		set("no_sell",1);
		set("value",100);
		set("unit","颗");
		set("long","一块普通的晶石，好象是传说中七彩水晶风化后的产物。\n");
	}
	setup();
}
