#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "山路");
  set ("long", @LONG

小山不高，山上树木繁多，显得非常有精神。林中鸟尔叽叽喳喳
的叫着，时不时路边的草丛中窜出只野兔，惊起几只鸟雀。
LONG);

  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/lingxuzi" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "westdown" : __DIR__"to-baoxiang3",
  "southeast" : __DIR__"to-baoxiang5",
]));

  setup();
}

