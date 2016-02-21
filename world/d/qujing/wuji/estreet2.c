// Room: /u/mimi/zhuziguo/eaststreet2.c  snowcat moved to /d/qujing/wuji
inherit ROOM;

void create ()
{
  set ("short", "坤元街");
  set ("long", @LONG

这里是坤元街中段，路两旁挤满了做生意的小贩。北边有一家裁衣
店，南边是一家客店。

LONG);

  set("exits", ([ /* sizeof() == 3 */
    "west" : __DIR__"square.c",
    "south" : __DIR__"kezhan.c",
    "east" : __DIR__"estreet",
  ]));
  set("objects", ([
      __DIR__"npc/people" : 3,
  ]));
  set("outdoors", __DIR__"");                  

  setup();
}
