// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/dianmen.c

inherit ROOM;
#include <room.h>

void create ()
{
  set ("short", "殿门");
  set ("long", @LONG

这里是三清观的殿门，殿门红木青檐翻修一新，门口织锦裹柱
且绣有二十二个大字：“雨顺风调，愿祝天尊无量法；河清海
晏，祈求万岁有余年。”

LONG);

  set("item_desc", ([
        "east" : (: look_door, "east" :),
      ]));
  set("exits", ([
        "southdown"    : __DIR__"banlu1",
        "west"         : __DIR__"zhai",
        "east"         : __DIR__"wugu",
        "north"        : __DIR__"sanqing",
      ]));
  set("objects", ([
        __DIR__"npc/daozhang"    : 1,
      ]));
  set("outdoors","/d/qujing/chechi");
  create_door("east", "小门", "west", DOOR_CLOSED);
  setup();

}

