//xitian.c
//created 4-8-97, pickle

#include <room.h>
#include <ansi.h>
inherit ROOM;

int valid_leave();

void create ()
{
  set ("short", "西天门");
  set ("long", @LONG

    西门靠近天宫的平乐殿，是玉帝大宴群臣的地方。墙里传来阵阵
仙乐，大概是仙女们在跳舞吧。你听着美妙的音乐，不由得陶醉了。
唉，天上一日，人间一年。你到现在才知道为什么在天宫里时间过得
那么快。

LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "east" : (: look_door,     "east" :),
]));
  set("objects", ([ /* sizeof() == 3 */
  __DIR__"npc/tian-ding2" : 1,
  __DIR__"npc/tian-ding1" : 1,
//  __DIR__"npc/tian-bing" : 4,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"wn1",
  "south" : __DIR__"ws1",
  "east" : __DIR__"ximenting",
]));
create_door("east", "西天门", "west", DOOR_CLOSED);
  set("no_clean_up", 2);

  setup();
}

int valid_leave(object me, string dir)
{
 
        if (dir != "east") {
                return ::valid_leave(me,dir);
        }
 
if (::valid_leave(me,dir)) return notify_fail("贵宾才能从西门出入，尊驾还是从南门进吧！\n");
}
