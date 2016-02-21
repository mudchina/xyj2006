#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "五凤楼");
  set ("long", @LONG

一座小巧的彩楼，每到黄道吉日，国王便在这里大宴群臣，偶尔
也会在这里接见外国的使者。地下铺着豪华漂亮的地毯，两边没
有桌椅，所有的客人都坐在地下。
LONG);

  set("objects", ([ /* sizeof() == 1*/ 
__DIR__"npc/king" : 1,
]));
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"yunqi",
]));
	set("no_fight", 1);
	set("no_magic", 1);
  setup();
}

