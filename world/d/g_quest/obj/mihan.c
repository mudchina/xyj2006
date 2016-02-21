
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(RED"密函"NOR, ({ "mi han", "han" }) );
	set("long", "这是一张密函。\n");
	set_weight(3000);
	set("unit", "张");
	setup();
}

string long()
{
	object target;
	
	if(this_player()!=query("master"))
		return "这是一张密函。\n";
	if(objectp(target=query("target")))
		return sprintf("这是一张太平公主叫你送给%s(%s)的密函。\n"
			, WHT+target->name(1)+NOR,
			capitalize(target->query("id")));
	return "这是一张密函。\n";
}
