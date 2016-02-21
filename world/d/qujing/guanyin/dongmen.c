inherit ROOM;
#include <room.h>
void create ()
{
  set ("short", "洞门");
  set ("long", @LONG

悬崖下有一个洞门，洞门上有一横石板，上面写着“黑风山
黑风洞”六个大字。门前花香四散。两扇紧闭的石门。
LONG);
  set("outdoors", __DIR__);
 
 set("objects", 
        ([ //sizeof() == 3
                __DIR__"npc/guai1" : 2,
        ]));

  set("exits", ([
       "south" : __DIR__"tianjing",
        "north"  : __DIR__"lingdao5",
      ]));
create_door("south", "石门", "north", DOOR_CLOSED);
  setup();
  "obj/board/shibei_b"->foo();
}

int valid_leave(object me, string dir)
{       
   if (! me->query_temp("apply/name") ||
   me->query_temp("apply/name")[0] != "凌虚子")
   {
   if (dir == "south") 
   return notify_fail("小妖探出头喝道：我看你是活腻了！\n");
   return ::valid_leave(me, dir);
      }
  return 1;
 }
