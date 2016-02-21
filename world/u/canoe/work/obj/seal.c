#include <ansi.h>

inherit ITEM;
string *list=({/*"yg-qiankun","yg-jianmang","yg-jianzhang","yg-zxzx",*/
		"yg-sanshou",
               /*"yg-xueshan",
                "yg-ba","yg-jldl","yg-xiao","yg-yanluo","yg-kunlun","yg-sanban",
	       */});

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
	if(stringp(query("desc")))
		return "一张画了神奇符咒的桃符纸。可以(burn)来抓鬼。\n"+
		"只见上面画着：\n"+HIR+query("desc")+NOR+"\n这个妖怪上次似乎在"+HIY+query("where")
		+NOR+"出现过。\n任务类型："+query("kind")+"妖\t难度："+query("level")+"级\t还能用"+query("times")+"次\n";
}

void init()
{
	add_action("do_burn", "burn");
if( (int)this_object()->query("created") != 1 )
	{
		this_object()->set("created", 1);
		remove_call_out ("destroy_it");
		call_out ("destroy_it", 300);//5 min

	}
}
void destroy_it()
{
	message_vision("一阵风吹来，" + (string)this_object()->query("name") + "片片碎落，随风而去。\n", environment(this_object()));
	destruct(this_object());
}

int do_burn(string arg)
{
	object room,guai,me;
	me=this_player();
	
	if(!arg||!id(arg))
		return notify_fail("你要烧什么？\n");
	this_object()->set("times",(int)this_object()->query("times")-1);
	if(query("times")<1)
	{
	destroy_it();
	}
	message_vision(RED"$N大喊一声“妖魔鬼怪快现身”，手一挥，祭出了一张抓鬼符。。。\n\n"NOR, me);
	if(!query("master")||query("master")!=me)
	{
		message_vision("结果什么都没有发生。\n", me);
		destroy_it();
		return 1;
	}
	room=environment(me);
	if(file_name(room)+".c"!=query("file_name"))
	{
		message_vision("结果什么都没有发生。\n", me);
		return 1;
	}
	guai = new(__DIR__+"npc/"+list[random(sizeof(list))]);
	if(guai->move(room))
	{
	guai->copy_status(me,(int)this_object()->query("level"));
	guai->set("owner", me);
	guai->set("kind",me->query("canoetask/kind"));
	guai->set("level",(int)this_object()->query("level"));
	me->set("canoetask/guai",guai);
       	message_vision(HIB"只见一道亮光闪过，$N被抓鬼符给照出原形。\n"NOR,guai,me);
	destruct(this_object());
	return 1;
	}
	else write("妖怪复制不成功！\n");
	return 1;
}
