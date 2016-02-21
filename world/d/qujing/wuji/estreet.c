// Room: /u/mimi/zhuziguo/eaststreet  snowcat moved to /d/qujing/wuji
inherit ROOM;

void create ()
{
  set ("short", "坤元街");
  set ("long", @LONG

坤元街是乌鸡国最繁华的一条街。人来人往，好不热闹。北边是一
家茶馆，南边是一家水果店。
LONG);

  set("exits", ([ /* sizeof() == 3 */
      "west" : __DIR__"estreet2.c",
    "south" : __DIR__"fruit.c",
    "east" : __DIR__"eastgate",
  ]));
  set("objects", ([
      __DIR__"npc/people" : 3,
  ]));
  set("outdoors", __DIR__"");

  setup();
}
