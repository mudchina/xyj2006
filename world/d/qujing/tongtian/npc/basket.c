//Cracked by Roath
#include <ansi.h>
inherit ITEM;
void create()
{
	set_name("竹篮",({"devine basket"}));
	set("long", "一只精巧的竹篮，是用紫竹编织成的．\n");
	set("material","magic");
	set_weight(100);
	set_max_encumbrance(400000);
	if(clonep())
		set_default_object(__FILE__);
	else{
	set("unit", "只");
	set("no_get", 1);
	set("no_drop",1);
	set("no_sell",1);
	set("no_give",1);
	set("amount", 1);
}
	setup();
}
int is_container() {return 1;}
