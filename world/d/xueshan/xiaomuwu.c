//standroom.c used by weiqi...others may hate this format:D
//xiaomuwu.c

inherit ROOM;

void create ()
{
	set ("short", "小木屋");
	set ("long", @LONG

走进这间小木屋，你又吃了一惊。这里居然暖烘烘的，跟外面
的冰天雪地仿佛是两个世界。屋内靠墙摆着一圈大大小小的花
盆，里面种着各式各样叫不上名子的花草。屋里很安静，只有
一位绝色女子正对着火炉发呆。看到你进来，惊讶地啊了一声，
然后又继续发呆。
LONG);

	//set("item_desc", ([" *** " : " *** ", ]));
	//for look something.

	set("exits", 
	([ //sizeof() == 4
		//"south" : __DIR__"xiaomuwu",
		"north" : __DIR__"eroad2",
		//"west" : __DIR__"eroad1",
		//"east" : __DIR__"eroad3",
		//"up" : __DIR__"***",
		//"down" : __DIR__"***",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		__DIR__"npc/kongque-gongzhu" : 1,
	]));


	set("outdoors", "xuesan");

	setup();
}

//void init()
//{
	//add_action("do_jump", "jump");
//}

//int do_jump(string arg)
//{
       
//}

void open_down()
{//this open_down() will be called by the NPC "kongque-gongzhu".
	object downroom;

	if( !(downroom = find_object(__DIR__"dixiashi")) )
		downroom = load_object(__DIR__"dixiashi");

	//if( downroom = find_object(__DIR__"dixiashi") ) 
	//{
		set("exits/down", __DIR__"dixiashi");
		downroom->set("exits/up", __FILE__);
		message("vision", "桌子底下突然发出轧轧的声音，露出一个向下的洞口，还垂着一张软梯。\n", this_object() );
		message("vision", "天花板上忽然发出轧轧的声音，一张软梯垂了下来。\n", downroom );
	//}

	call_out("close_down", 10);
}

void close_down()
{
	object downroom;

	if( !query("exits/down") ) return;

	message("vision", "桌子底下发出轧轧的声音，洞口又封上了。\n", this_object() );

	if( downroom = find_object(__DIR__"dixiashi") ) 
	{
		message("vision", "天花板上发出轧轧的声音，软梯被收了上去。\n", downroom );
		downroom->delete("exits/up");
	}

	delete("exits/down");
}

