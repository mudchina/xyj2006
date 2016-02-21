#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "金光寺");
  set ("long", @LONG

门前有一横匾，上书七个镏金大字“赦建护国金光寺”。大门上
挂着把生了绣的铜锁，好象很久没有打开了的样子、只有偏门略
开一缝供人出入。偶尔几个僧人进出，也是低头快步，不敢略有
停留。
LONG);

//  set("objects", ([ /* sizeof() == 1*/ 
//  __DIR__"npc/erlang" : 1,
//]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"inner1",
  "west" : __DIR__"south1",
  "east" : __DIR__"south2",
]));
  create_door("north", "偏门", "south", DOOR_CLOSED);

  setup();
}
