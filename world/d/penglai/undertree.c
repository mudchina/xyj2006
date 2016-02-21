//Cracked by Roath
inherit ROOM;
#include <room.h>

void create ()
{
  set ("short", "白云洞外，松阴之下");
  set ("long", @LONG

一棵高有数丈的大松树如伞如盖遮住了天空，松树上垂挂着许
多荜萝葛藤，中见隐见些小花。松树下有一大石台，上面刻了
一个围棋盘，石台旁有三个石凳。数丈外有一石洞，洞前石碑
上刻着「白云洞」三个大字。
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "enter" : "洞中白云绕绕，什么也看不清楚。\n",
]));
  set("exits", ([ /* sizeof() == 3 */
  "enter" : __DIR__"baiyun0",
  "southdown" : __DIR__"penglai",
]));

  set("objects", ([ 
  __DIR__"npc/shouxing" : 1,
  __DIR__"npc/luxing" : 1,
  __DIR__"npc/fuxing" : 1,
]));
  setup();
}

int valid_leave(object me, string dir)
{
	if ( dir == "enter"){
		if(objectp(present("shou xing", environment(me))))
			return notify_fail("寿星伸手拦住你：里面是老夫卧室，你去干什么？\n");
//                if(objectp(present("fu xing", environment(me))))
//                        return notify_fail("福星伸手拦住你：里面是老夫卧室，你去干什么？\n");  
//                if(objectp(present("lu xing", environment(me))))
//                        return notify_fail("禄星伸手拦住你：里面是老夫卧室，你去干什么？\n");  
	return ::valid_leave(me, dir);
	}


return ::valid_leave(me, dir);
}

