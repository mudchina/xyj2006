// rewritten by snowcat.c 4/4/1997
// room: /d/nuerguo/juxianan.c

#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "聚仙庵");
  set ("long", @LONG

聚仙庵依山而建，布设甚是精巧。所谓“小桥通活水，茅舍
倚青山”，在风水上可称之为宝地。此刻庵门紧闭。有一道
士懒洋洋地盘坐在庵前绿茵之上，不知是在打坐修炼还是在
晒太阳。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "enter" : __DIR__"annei",
  "northdown" : __DIR__"jieyang",
]));

  create_door("enter","庵门","out",DOOR_CLOSED); 

  set("objects", ([
         __DIR__"npc/daoshi" : 1,
      ]));
  set("outdoors", __DIR__"");

  setup();
}






