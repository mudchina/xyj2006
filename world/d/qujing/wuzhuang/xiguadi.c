//Cracked by Roath
//huludi.c
#include <ansi.h>

inherit ROOM;

void create ()
{
	set ("short", "西瓜地");
	set ("long", @LONG

五庄观做事的多，吃饭的也不少，所以观内雇了附近的一些农家
来种蔬菜瓜果。这里是西瓜地。往北是有一道荆棘结成的篱笆，
篱笆上开了一道简陋的杏木门，门上挂着一把黄铜锁。
LONG);

	set("exits", 
	([ //sizeof() == 4
		"southeast" : __DIR__"baicaidi",
		"southwest" : __DIR__"huludi",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		"/d/obj/food/watermelon" : 3,
	]));

	//create_door("north", "杏木门", "south", DOOR_CLOSED);
	set("outdoors", "wuzhuang");

	setup();
}

void init()
{
	add_action("do_open", "open");
}

int do_open(string arg)
{
	object me, key, nroom;

	me = this_player();

	if( !arg || arg != "door" ) 
		return notify_fail("你要打开什么？\n");

//    if( !(key = present("huangtong key", me) && key->query("id")=="huangtong key") ) 
  key=present("huangtong key",me);
  if (!key || key->query("id")!="huangtong key")
		return notify_fail("你没有开这道门的钥匙。\n");

	//now we are ready to open...

      if( !(nroom = find_object(__DIR__"renshenguo-yuan")) )
                nroom = load_object(__DIR__"renshenguo-yuan");

        if( nroom = find_object(__DIR__"renshenguo-yuan") ) 
        {
                set("exits/north", __DIR__"renshenguo-yuan");
                message_vision("$N把黄铜钥匙插在锁孔里拧了半天，终于把锁打开了,杏木门开了。\n", me);
                nroom->set("exits/south", __DIR__"xiguadi");
		me->set_temp("used_huangtong_key", 1);
		destruct(key);
                call_out("close_door", 600);
	}
	return 1;
	
}

void close_door()
{
        object nroom;

        message("vision", "一个小道士飞快的跑过来,把门又锁上了。\n", this_object() );
        if( nroom = find_object(__DIR__"renshenguo-yuan")) {
        message("vision", "一个小道士飞快的跑过来,把门又锁上了。\n", nroom);
        nroom->delete("exits/south");
        }

        delete("exits/north");
}
