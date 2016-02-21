//standroom.c used by weiqi...others may hate this format:D
//eroad1.c

inherit ROOM;

void create ()
{
	set ("short", "冰崖底");
	set ("long", @LONG

这里是冰崖底下。冰谷中别的地方基本上寸草不生。这里却从冰
缝中钻出几株小草(xiaocao)，这种草叶尖圆润，色泽幽蓝，看起
来不象能在这绝地酷寒中生长的样子。再往东去可以见到一座不
大的小木房。北面则见冰宫在冰雪映照下奕奕生光。
LONG);

	set("item_desc", (["xiaocao" : "这种草叶尖圆润，色泽幽蓝，的确好看。 \n", ]));
	//for look something.

	set("exits", 
	([ //sizeof() == 4
		//"south" : __DIR__"***",
		//"north" : __DIR__"icegate",
		"west" : __DIR__"xuelu",
		"east" : __DIR__"eroad2",
		//"up" : __DIR__"***",
		//"down" : __DIR__"***",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		"/d/obj/misc/ice" : 2,
	]));


	set("outdoors", "xueshan");

	set("no_xiaocao", 0);

	setup();
}

void init()
{
	add_action("do_dig", "dig");
	add_action("do_dig", "wa");
}

int do_dig(string arg)
{

	object ob, me;
	
	me=this_player();

	if( (!arg) || (arg != "xiao cao" && arg != "xiaocao" && arg != "cao" && arg !="小草") )
		return notify_fail("你要挖什么？\n");

	if( !(ob = me->query_temp("weapon")) || ( (string)ob->query("skill_type")!="axe" && (string)ob->query("skill_type")!="blade" && (string)ob->query("skill_type")!="sword" ) ) 
		return notify_fail("得找个好工具吧。\n");

	if (query("no_xiaocao"))
		return notify_fail("没几棵了，再挖孔雀公主非宰了你不可。\n");

	ob=new("/d/obj/misc/xiaocao");
        	ob->move(me);
	message_vision("$N挖出一颗蓝色小草，小心翼翼地藏到了怀里。\n", me);
	set("no_xiaocao", 1);
	call_out("regenerate", 300);
	return 1;
}

int regenerate()
{
	set("no_xiaocao", 0);
	return 1;
}


