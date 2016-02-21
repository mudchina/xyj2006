
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(YEL"公文"NOR, ({ "gong wen", "wen" }) );
	set("long", "这是一张长安府的公文。\n");
	set_weight(3000);
	set("unit", "张");
	setup();
}

string long()
{
	object target;
	
	if(this_player()!=query("master"))
		return "这是一张长安府的公文。\n";
	if(objectp(target=query("target")))
		return sprintf("这是一张户部尚书叫你送给%s(%s)的公文。\n"
			, YEL+target->name(1)+NOR, 
			capitalize(target->query("id")));
	return "这是一张长安府的公文。\n";
}
