// created by wxb 12/24/1998
// room: /d/qujing/huangfeng/chufang.c

#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "厨房");
  set ("long", @LONG

村长家的厨房里蒸气弥漫，菜香扑鼻。一个年长的妇人正忙
着准备晚饭，看到你进来似乎吃了一惊。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"minju2",
]));
  set("objects", ([ /* sizeof() == 4 */
  __DIR__"npc/woman" : 1,
  __DIR__"obj/shanyao" : 1,
  __DIR__"obj/yutou" : 1,
]));
  setup();
}
