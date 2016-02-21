//Cracked by Roath
// lingdan.c 灵丹 

inherit ITEM;

void destroy();

void init()
{
//	if (!wizardp(this_player())) {
//		set("no_give", "这样东西不能随便给人。\n");
//		set("no_drop", "这么宝贵的灵丹，哪能乱扔! \n");
//	}
set("no_sell",1);
	add_action("do_eat", "eat");
	call_out("destroy", 120);
}

void create()
{
	set_name("灵丹", ({"lingdan", "dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "粒");
		set("long", "这是一粒贵重的灵丹，吃下去能够养精活血。不过时间一长药性就会消失，灵丹也会无影无踪的。\n");
		set("value", 5000);
	}
	setup();
}

int do_eat(string arg)
{
	if (!id(arg))
		return notify_fail("你要吃什么？\n");
	if ((int)this_player()->query("eff_sen") == 
	    (int)this_player()->query("max_sen"))
		return notify_fail("你现在精血充足。\n");
	else {
		this_player()->receive_curing("sen", 50);
		message_vision("$N拿起一粒灵丹往嘴里一扔，嚼也没嚼就吞了下去。\n", this_player());
		destruct(this_object());
		return 1;
	}
}

void destroy()
{
destruct(this_object());
}

