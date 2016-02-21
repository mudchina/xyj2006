
#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "灌江");
  set ("long", @LONG

灌江水面不宽，江水缓缓向东流去。江面上偶尔出现几只打渔
的小船。一条土路顺江而铺，向东直通到灌江入长江的灌江口。
路上偶有几个行人，都是神色匆匆，忙着赶路。
LONG);


//  set("objects", ([ /* sizeof() == 1*/ 
//  __DIR__"npc/spring-gongcao" : 1,
//]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "west" : "/d/meishan/guanjiang1",
  "east" : __DIR__"guanjiang3",
]));

  setup();
}

