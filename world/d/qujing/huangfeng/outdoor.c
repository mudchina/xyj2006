//Cracked by Roath

inherit ROOM;

void create ()
{
  set ("short", "庄院门前");
  set ("long", @LONG

紫枝翳翳，白石苍苍。紫枝翳翳多青草，白石苍苍半绿台。数点小
荧光灼灼，一林野树米排排。香兰馥郁，嫩竹新栽。清泉流曲涧，
古柏依深崖。地僻更无游客到，门前唯有野花开。

LONG);

  set("exits", ([
        "south"  : __DIR__"shanlu2new",
      ]));
  set("outdoors","hfd");
  setup();
}

void init()
{
  add_action("do_knock", "knock");
  add_action("do_knock", "qiao");
}
int do_knock(string arg)
{
        object me;

        me=this_player();

        if( !arg || (arg != "men" && arg != "door" && arg != "门" ) )
                return notify_fail("你要敲什么？\n");       
        call_out("open_up", 1);
        return 1; 
}

void open_up()
{
	        object room; 

        	if( !(room = find_object(__DIR__"indoor")) )
                room = load_object(__DIR__"indoor");

                set("exits/enter", __DIR__"indoor");
		room->set("exits/out", __DIR__"outdoor");
		message("vision", "庄院的门被人打开了。\n", room);
		message("vision", "庄院的门被人打开了。\n", this_object());

        call_out("close_up", 100);
}

void close_up()
{
        object room;

        if( !query("exits/enter") ) return;
	message("vision", "庄院的门自己关上了。\n", this_object());


        if( room = find_object(__DIR__"indoor") ) 
        {
		message("vision", "庄院的门自己关上了。\n", room);
                room->delete("exits/out");
        }

        delete("exits/enter");
}


