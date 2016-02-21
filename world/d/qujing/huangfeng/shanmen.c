// created by wxb 12/24/1998
// room: /d/qujing/huangfeng/shanmen.c

inherit ROOM;
#include <room.h>

void create ()
{
  set ("short", "山门");
  set ("long", @LONG

小路尽头两扇朱红大门，门上悬着一块匾额，上书“讲经禅院”
四个金漆大字。门口有两个道人，见你行来一齐躬身行礼。

LONG);

  set("exits", ([
        "southdown"    : __DIR__"yangchanglu6",
        "north"        : __DIR__"chanyuan",
      ]));
  set("objects", ([
       __DIR__"npc/ykdaoren":2
      ]));
  set("outdoors", __DIR__);
  setup();

}

