// inside1.c

inherit ROOM;

void create ()
{
  set ("short", "广场");
  set ("long", @LONG

在宫门与正宫之间是一个巨大的广场．一些虾兵蟹将正在这里操练　　　
着武艺。还有几名宫娥端着盒子进进出出。南北的偏宫是龙太子和　　　
公主住的地方，向东就到了正殿。
LONG);

  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/soldier1" : 1,
  __DIR__"npc/gonge" : 1,
 __DIR__"npc/zhangmen": 1,
]));
  set("exits", ([ /* sizeof() == 4 */
  "eastup" : __DIR__"yujie1.c",
  "southeast" : __DIR__"girl1",
  "west" : __DIR__"gate",
  "northeast" : __DIR__"boy1",
]));
//      
        set("water", 1);
//  
        setup();
}

