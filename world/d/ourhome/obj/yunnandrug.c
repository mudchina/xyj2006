// yunnandrug.c 云南白药

inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name("云南白药", ({"yunnan baiyao", "baiyao", "yao","drug"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "瓶");
		set("long", "这是一瓶贵重的云南白药，省着点用。\n");
		set("value", 5000);
		set("no_sell",1);
	}
	setup();
}

int do_eat(string arg)
{
	if (!id(arg))
		return notify_fail("你要吃什么药？\n");
	if ((int)this_player()->query("eff_kee") == 
	    (int)this_player()->query("max_kee"))
		return notify_fail("没病别乱吃药。\n");
	else {
		this_player()->receive_curing("kee", 50);
		message_vision("$N拿起瓶云南白药往嘴里一倒，胡乱咽了下去。\n", this_player());
		destruct(this_object());
		return 1;
	}
}

