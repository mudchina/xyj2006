//Cracked by Roath
inherit ROOM;
#include <room.h>

void create ()
{
  set ("short", "山后小路");
  set ("long", @LONG

蓬莱岛上风光秀丽，当真是好去处！山后的小路两边奇花异草
不绝，满目香艳。上有奇松古藤，多有仙鸟停歇。前面一座石
崖高耸，南方有一小孔，透出几许明光。
LONG);
  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"baiyun19",
  "north": __DIR__"yaxia",
]));
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/baiyuan" : 1,
]));

	set("outdoors", 1);
  setup();
}

int valid_leave(object me, string dir)
{       
        object a;
        if( wizardp(me)) return 1;

        if (dir == "north") {
                if(objectp(a=present("bai yuan", environment(me))) && living(a) )
                return notify_fail("白猿舞动手中长剑，好象不愿让你过去！\n");
        return ::valid_leave(me, dir);
        }

        return 1;
}

