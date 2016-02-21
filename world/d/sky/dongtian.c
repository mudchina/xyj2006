//dongtian.c
//created 4-8-97, pickle

#include <room.h>
#include <ansi.h>
inherit ROOM;

int valid_leave();

void create ()
{
  set ("short", "东天门");
  set ("long", @LONG

   东门就在马厩之侧，御马纵声长嘶，声传数里。这些千里良驹成
天养尊处优，饮食不愁，为何还要长鸣呢？是不是因为不能一展骏足
而仰天长叹？

LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "west" : (: look_door,     "west" :),
]));
  set("objects", ([ /* sizeof() == 3 */
  __DIR__"npc/tian-ding2" : 1,
  __DIR__"npc/tian-ding1" : 1,
//  __DIR__"npc/tian-bing" : 4,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"dongmenting",
  "north" : __DIR__"en1",
  "south" : __DIR__"es1",
  "east": __DIR__"yun1",
]));

create_door("west", "东天门", "east", DOOR_CLOSED);
  setup();
}

int valid_leave(object me, string dir)
{
 
        if (dir == "west") {
		if(member_array("zengzhang tianwang", me->parse_command_id_list())==-1
		&& member_array("huguo tianwang", me->parse_command_id_list())==-1 ){
			if(present("tian ding", environment(me) ))
				return notify_fail("大力天丁对你一挥手，嚷道：闲人免进！\n");
		}



                return ::valid_leave(me,dir);
        }
	return ::valid_leave(me,dir);
}

