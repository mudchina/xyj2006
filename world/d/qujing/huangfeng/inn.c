// created by wxb 12/24/1998
// room: /d/qujing/huangfeng/inn.c

inherit ROOM;

void create()
{
  set ("short", "小酒店");
  set ("long", @LONG

山前小店，南来北往的行人都喜欢在这里喝上一杯，虽然店
不是很大，经营的东西不是什么特别好的货色，但在这荒山
野岭之中却又难得之至，所以客人很多。一个伙计前前后后
的忙着。

LONG);
set("exits", ([ /* sizeof() == 1 */
"north" : __DIR__"tulu1",
]));
set("objects", ([
                __DIR__"npc/xiaoer": 1, ]) );

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
