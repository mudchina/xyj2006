#include <room.h>
inherit ROOM;


int valid_leave();

void create ()
{
  set ("short", "斩妖台");
  set ("long", @LONG

玉皇封托塔李天王为五界降魔大元帅，给了他先斩后奏的宏愿。
四方的斩妖台正中立一五尺多高雕符篆玉柱，四方神兵守护，端
地是杀气腾腾。
LONG);

  set("exits", ([ /* sizeof() == 1 */
    "west" : __DIR__"yongdao",
  ]));
  set("outdoors", 1);
  set("objects", ([ /* sizeof() == 3 */
  __DIR__"npc/shenbing" : 2,
]));

  setup();
}


