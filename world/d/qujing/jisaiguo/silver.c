#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "银器铺");
  set ("long", @LONG

银器铺正前摆了张木柜，里面陈列这各种银器，大多是女人的饰
品，也有些其他的小玩艺。柜台后站着位花枝招展的女老板，笑
盈盈的看着你。再往后是作坊，几个老匠人正忙着打制。
LONG);

  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/ayina" : 1,
]));
//  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"westmarket",
]));

  setup();
}

