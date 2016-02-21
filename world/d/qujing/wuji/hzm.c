// Room: /u/mimi/zhuziguo/houzaimen.c  snowcat moved to /d/qujing/wuji
inherit ROOM;

void create ()
{
  set ("short", "后宰门");
  set ("long", @LONG

这里是王宫的偏门，看上去冷冷清清的，只有几个老太监无所事事
地在那儿打瞌睡。

LONG);

  set("exits", ([ /* sizeof() == 2 */
    "east" : __DIR__"jxt",
    "south" : __DIR__"wall.c",
  ]));
  set("objects", ([
    __DIR__"npc/taijian" : 2,
  ]));

  setup();
}
