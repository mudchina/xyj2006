//Cracked by Roath
// Room: /d/moon/xiaoyuan.c

#include <ansi.h>
#include <room.h>
inherit ROOM;

int do_stand(string temp2);
int do_sit(string temp3);

void create ()
{
  set ("short", "篱笆小院");
  set ("long", @LONG

篱笆围成的小院。地上种满了奇花异草。中间有一张木桌及几只小木凳，
桌上摆着各色果品。东，西，北各有一间精致的小屋。
LONG);

  set("objects", ([ /* sizeof() == 4 */
  __DIR__"obj/guihuageng" : 1,
  __DIR__"obj/jiudai" : 1,
  __DIR__"npc/yuenu" : 1,
  __DIR__"obj/xueli" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"eroom",
  "north" : __DIR__"nroom",
  "south" : __DIR__"ontop2",
  "west" : __DIR__"wroom",
]));
  set("valid_startroom", 1);

  setup();
  call_other("/obj/board/moon_b", "???");
}

void init()
{
	add_action("do_stand", "stand");
	add_action("do_sit", "sit");
}

int do_sit(string arg)
{     
      object me;

      me=this_player();

	if ( !arg || ((arg != "seat")&&(arg != "deng")&&(arg != "table") ))
		return notify_fail("你要坐在什么上面？\n");	
	
	if (this_player()->query_temp("marks/sit"))
		return notify_fail("你已经坐下了。\n");	
      
      if ( arg != "seat"&&arg != "deng")	
	      return notify_fail("坐桌子上？太不雅观了吧。\n");
        	
	this_player()->set_temp("marks/sit", 1);
	message_vision("$N轻轻巧巧地坐上了小木凳。\n",me);
      return 1;	
}

int do_stand(string arg)
{
      object me;

      me=this_player();

      if (!this_player()->query_temp("marks/sit"))
          return notify_fail("你本来就站着。\n");

      this_player()->set_temp("marks/sit", 0);
      message_vision("$N伸了个懒腰，站了起来。\n", me);
      return 1;
}


