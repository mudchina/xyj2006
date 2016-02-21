
#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "圣泉祠");
  set ("long", @LONG

路边草木渐稀，离路数尺有一泉，泉边有一祠。周围山如屏障
环绕，颇为美妙。祠前的冬青和柏树成行，都有上百的年龄。
LONG);


  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/zhang" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "southwest" : "/d/meishan/fenglin1",
  "east" : __DIR__"fenglin2",
  "southeast" : __DIR__"longwan",
  "northup" : __DIR__"zhaoyun",
]));

  setup();
}


