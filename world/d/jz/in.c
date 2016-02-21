//Cracked by Roath
// /d/jz/in.c
// 妖神之争 1.0
// by happ@YSZZ 200.04.02

inherit ROOM;
void create()
{
  set ("short", "内室");
  set ("long", @LONG

这是一个布置的很得体的房间，盆景，屏风，样样都让人觉得摆
的很合适。一走进来，你就闻到一种青香，当然也只有官宦人家
才会有如此的摆设。
LONG);

  set("exits", ([ /* sizeof() == 1 */
         "east" : __DIR__"datang",
        ]));
  set("objects", ([
        __DIR__"npc/yin" : 1,
        ]));
        setup();
}
int valid_leave(object me, string dir)
{

        if (objectp(present("liu hong", environment(me)))
         || objectp(present("li biao", environment(me))) )
        return notify_fail("你现在不能离去！\n");
        return ::valid_leave(me, dir);
}
