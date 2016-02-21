#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "云霁台");
  set ("long", @LONG

祭赛国中非常的繁华，王宫便在那城心。一个高有数丈的高台将
王宫和闹市分开。从高台上可以附视全城，只见高楼宫宇不断，
街上来往人等衣冠隆重，足显民富豪华。几个黄门官正在台前巡
视，防止闲杂人等如内。
LONG);

  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/guan" : 2,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"centermarket",
  "north" : __DIR__"wufeng",
]));

  set("valid_startroom", 1);
  setup();
}

int valid_leave(object me, string dir)
{       
	object a,b;
        if( wizardp(me)) return 1;
	if( present("shu tie", me) ) return 1;
	if( present("xiazi", me) ) return 1;
        if( present("tooth", me) ) return 1;

        if (dir == "north") {
                if(objectp(a=present("guan", environment(me))) && living(a) )
		return notify_fail("黄门官举起手中弯刀，挡住了你的去路。\n");
                if(objectp(b=present("guan 2", environment(me))) && living(b) )
                return notify_fail("黄门官举起手中弯刀，挡住了你的去路。\n");

        return ::valid_leave(me, dir);
        }

        return 1;
}

