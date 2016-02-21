//restroom.c

inherit ROOM;

void create ()
{
	set ("short", "休息室");
	set ("long", @LONG

这里是雪山弟子平时休息的地方。屋中央有一张大石桌，上面摆
着一些水果点心。边上还有两个里间。其中靠南的一间门上挂着
一张牌子(paizi)。而墙上则乱七八糟地写满了字。
LONG);

	set("item_desc", (["paizi" : "女弟子卧房，男子严禁入内。\n", ]));
	//for look something.

	set("exits", 
	([ //sizeof() == 4
		"south" : __DIR__"girlroom",
		"north" : __DIR__"boyroom",
		"east" : __DIR__"shanpo",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		"/d/obj/misc/seat" : 2,
		"/d/obj/misc/table" : 1,
                "/d/xueshan/npc/xunshi" : 2,
	]));

	set("valid_startroom", 1);

	set("outdoors", "xueshan");

	setup();

	"/obj/board/xueshan_b"->foo();
}




int valid_leave(object me, string dir)
{
    if (dir == "south" && objectp(present("xunshi", environment(me)))) 
      {
      if ( me->query("gender") == "男性" ) 
         {
         return
         notify_fail("冰谷巡使喝道：女弟子卧房，男子严禁入内！\n");
         }
      }
      else 
         { 
         return 
         ::valid_leave(me, dir); 
         }
      return 1;
}

