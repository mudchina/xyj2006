#include <room.h>
inherit ROOM;


int valid_leave();

void create ()
{
  set ("short", "云楼台");
  set ("long", @LONG

此乃宫上一小台，远望仙境，见金光万道滚红霞，瑞气千条喷紫
烟。远上长桥碧雾蒙，天宫宝殿映云光。当真是天上自来有仙境，
不堕人间点污泥。
LONG);

  set("exits", ([ /* sizeof() == 1 */
    "down": __DIR__"yunlou",
  ]));
  set("objects", ([ /* sizeof() == 3 */
  __DIR__"npc/litianwang" : 1,
]));

  set("outdoors", 1);
  setup();
}


