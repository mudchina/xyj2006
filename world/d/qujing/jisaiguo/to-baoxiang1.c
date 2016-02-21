#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "土路");
  set ("long", @LONG

西边望去有一座大的城池，笔直的土路直通向城中，乘马和徒步
赶路的人来往不绝，可见城中之繁华。东边土路向东北方向延伸，
渐渐隐在一座小山之后。
LONG);

//  set("objects", ([ /* sizeof() == 1*/ 
//  __DIR__"npc/erlang" : 1,
//]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"eastgate",
  "northeast" : __DIR__"to-baoxiang2",
]));

  setup();
}

