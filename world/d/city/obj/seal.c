#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("抓鬼符", ({"ghost seal", "seal", "paper"}));
	set_weight(100);
	if(clonep())
    		set_default_object(__FILE__);
  	else {

        set("long","一张画上了符咒的桃符纸。\n");
        set("unit", "张");
        set("value", 0);
	set("no_put",1);
	set("no_sell",1);
	}
	setup();
}

string long()
{
	if(query("finished"))
		return "一张由钟馗花了几道符咒的桃符纸。\n"+
		"已经有一只鬼被符咒给制住了。\n";
	if(stringp(query("desc")))
		return "一张由钟馗花了几道符咒的桃符纸。可以(burn)来抓鬼。\n"+
		"只见上面画着：\n"+
		query("desc");
}

void init()
{
	add_action("do_burn", "burn");
}

int do_burn(string arg)
{
	object room, me;
	string name;
	
	if(!arg||!id(arg))
		return notify_fail("你要烧什么？\n");
	me=this_player();
	
	if(query("finished"))
		return notify_fail("上面已经有一只鬼了，快回去交给钟馗吧。\n");
	if(!query("master")||query("master")!=me)
	{
		message_vision(RED"$N大喊一声“妖魔鬼怪快现身”，手一挥，祭出了一张抓鬼符。。。\n\n"NOR, me);
		message_vision("结果什么都没有发生。\n", me);
		destruct(this_object());
		return 1;
	}
	
	room=environment(me);
	message_vision(RED"$N大喊一声“妖魔鬼怪快现身”，手一挥，祭出了一张抓鬼符。。。\n\n"NOR, me);
	if(file_name(room)+".c"!=query("file_name"))
	{
		message_vision("结果什么都没有发生。\n", me);
		destruct(this_object());
		return 1;
	}
	name=({ "大头", "青面", "独角", "红发"})[random(4)];

	message_vision(HIB"只见一道亮光闪过，"+name+"鬼已经被抓鬼符给制住。\n"NOR, me);
	set("finished", 1);
	return 1;
}