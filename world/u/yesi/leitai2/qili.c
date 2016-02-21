// by snowcat

inherit ROOM;

void create ()
{
  set ("short", "七里酒楼");
  set ("long", @LONG

酒楼红梁绿瓦，外面挂着一匾大招牌：“七里酒楼”。楼里面摆着大
红木桌子，从里面不时地散发出一阵阵饭菜香酒香。酒楼的西面是大
街。

LONG);

  set("exits", ([
    "west" : __DIR__"yao5",
  ]));
  set("objects", ([ /* sizeof() == 2 */
    __DIR__"npc/hai" : 1,
  ]));
  set("resource", ([ /* sizeof() == 1 */
    "water" : 1,
  ]));
  setup();
}

