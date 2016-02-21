// rewritten by snowcat.c 4/4/1997
// Room: /nuerguo/annei.c

#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "庵内");
  set ("long", @LONG

虽说是道观，聚仙庵内供的既不是太上老君，也不是道家诸
仙，而是一口井(well)。井台上刻有三个大字：“落胎泉”。
一老道正坐在井台边闭目修炼。
LONG);

  set("item_desc",(["well":"一口深井，井架上挂着一只吊桶，用来打水。 \n",
        ]));
  set("exits", ([
    "out" : __DIR__"juxianan",
  ]));

  create_door("out","庵门","enter",DOOR_CLOSED); 

  set("objects", ([
         __DIR__"npc/niuer" : 1,
      ]));

  set("valid_startroom", 1);
  setup();
}






