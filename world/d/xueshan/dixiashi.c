//standroom.c used by weiqi...others may hate this format:D
//dixiashi.c

inherit ROOM;

void create ()
{
	set ("short", "地下室");
	set ("long", @LONG

的确没想到小木屋底下居然还有这么一间布置精巧的地下室。
这里也跟上面一样，三面靠墙摆满了大大小小的花盆，里面种
着各式各样叫不上名子的花草。另一面则是一张看起来相当舒
适的床铺，上面躺着一位看起来三四十岁的中年人。他的脸在
壁灯灯光下显得阴晴不定，有些说不出的诡异。地下室密不透
风，只在左面墙壁上似乎有些砸过的痕迹。
LONG);

	//set("item_desc", ([" *** " : " *** ", ]));
	//for look something.

	set("exits", 
	([ //sizeof() == 4
		//"south" : __DIR__"xiaomuwu",
		//"north" : __DIR__"eroad2",
		//"west" : __DIR__"eroad1",
		//"east" : __DIR__"eroad3",
		//"up" : __DIR__"***",
		//"down" : __DIR__"***",
	]));
	
	set("objects", 
	([ //sizeof() == 1
                  "/d/xueshan/npc/dapeng" : 1,
	]));


	//set("outdoors", "xuesan");

	setup();
}

void init()
{
	add_action("do_knock", "knock");
	add_action("do_knock", "qiao");
        add_action("do_hammer", "za");
}

int do_knock(string arg)
{
	object me, uproom;
	
	me=this_player();

	if( !arg || (arg != "wall" && arg != "qiang" && arg != "墙" && arg != "墙壁" ) )
		return notify_fail("你要敲什么？\n");       

/*
	if( !(uproom = find_object(__DIR__"xiaomuwu")) )
		uproom = load_object(__DIR__"xiaomuwu");

	if( uproom = find_object(__DIR__"xiaomuwu") )
	{
		uproom->open_down();
		return 1; 
	}
	else return notify_fail("看样子机关出毛病了，你耐心等一等吧。\n");
*/
	call_out("open_up", 1);
	return 1; 
}

void open_up()
{
	object uproom; 

/*
	if( !(uproom = find_object(__DIR__"xiaomuwu")) )
		uproom = load_object(__DIR__"xiaomuwu");
*/

	if( uproom = find_object(__DIR__"xiaomuwu") ) 
	{
		set("exits/up", __DIR__"xiaomuwu");
		uproom->set("exits/down", __FILE__);
		message("vision", "桌子底下突然发出轧轧的声音，露出一个向下的洞口，还垂着一张软梯。\n", uproom );
		message("vision", "天花板上忽然发出轧轧的声音，一张软梯垂了下来。\n", this_object() );
	}

	call_out("close_up", 10);
}

void close_up()
{
	object uproom;

	if( !query("exits/up") ) return;

	message("vision", "天花板上发出轧轧的声音，软梯被收了上去。\n", this_object() );

	if( uproom = find_object(__DIR__"xiaomuwu") ) 
	{
		message("vision", "桌子底下发出轧轧的声音，洞口又封上了。\n", uproom );
		uproom->delete("exits/down");
	}

	delete("exits/up");
}


int do_hammer(string arg)
{
  object me;
  me=this_player();
    if  (arg != "wall")
{
        return notify_fail("你要砸什么？\n");
return 1;
}
    if ( !present("hammer", me))
{
      return notify_fail("你挥起拳头往墙上砸去，哇！好疼！\n");
return 1;
}
   if(objectp(present("dapeng mingwang", environment(me))))
{
  message_vision("$N看到大鹏明王在，又把手缩了回来．\n", me);
return 1;
}
    message_vision("$N挥舞大锤，往墙上砸去．\n", me);
me->add("sen",-50);
me->add("kee",-50);
    message_vision("$N把墙砸开了一个洞，连忙钻了进去．\n", me);
      me->move("/d/xueshan/mishi");
    return 1;
 }
