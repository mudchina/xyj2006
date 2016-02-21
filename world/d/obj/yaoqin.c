
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIG"瑶琴"NOR, ({ "yao qin", "qin" }) );
	set("long", "这是一把古色古香的瑶琴。\n");
	set_weight(3000);
	set("unit", "把");
	setup();
}

string long()
{
	object target;
	
	if(this_player()!=query("master"))
		return "这是一把古色古香的瑶琴。\n";
	if(objectp(target=query("target")))
		return sprintf("这是一把红娘叫你送给%s(%s)的瑶琴。\n"
			, HIM+target->name(1)+NOR,
			capitalize(target->query("id")));
	return "这是一把古色古香的瑶琴。\n";
}
