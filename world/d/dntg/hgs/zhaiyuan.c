// Room: /d/4world/zhaiyuan.c
inherit ROOM;

void create()
{
  set ("short", "斋院");
  set ("long", @LONG

一个小小的院落，院中不大，却收拾地干干净净。院中散布几张
木桌，桌上摆了些碗筷之类。后面台上坐了个老头，台上摆了口
大锅及几个茶壶。你要是饿了的话可以向他要(yao)吃的。
LONG);
  set("outdoors", "/d/4world");
  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"west1",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/laotou" : 1,
  "/d/obj/food/baozi" : 2,
  "/d/obj/food/chahu" : 1,
]));
//  set("no_fight", 1);
//  set("no_magic", 1);
  set("resource", ([ /* sizeof() == 1 */
  "water" : 1,
]));

  setup();
}

int valid_leave()
{
        if((present("bao", this_player())))
            return notify_fail("老头对你说：吃完包子再走是这的规矩！\n");
	if(present("teapot", this_player()) )	
            return notify_fail("老头对你说：别把我的茶壶拿跑了！\n");
    return ::valid_leave();
}

