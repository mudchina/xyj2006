
#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "二郎庙");
  set ("long", @LONG

这里是二郎真君的庙宇。想当年齐天大圣孙悟空曾与二郎神
在此一场恶斗，如今故人依在，只是冷落了许多。真君的塑
像立于正前，似笑非笑地看着你。
LONG);


  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/miaozhu" : 1,
]));
  set("exits", ([ /* sizeof() == 2 */
  "south" : "/d/meishan/erlangwai",
]));

  setup();
}

