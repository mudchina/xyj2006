// Room: /d/qujing/wudidong/shanlu3.c

inherit ROOM;

void create ()
{
  set ("short", "山谷");
  set ("long", @LONG

出了山腹，你眼前一亮，原来身处一座深山之中，离张家村已远了。
东西北三面都是峭壁，只有南边一片黑松林似乎有路可寻。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "enter" : __DIR__"shanlu2",
  "southup" : __DIR__"shanlu4",
]));
  set("outdoors", 1);

  setup();
}
int valid_leave(object me, string dir)
{
  if (dir == "enter")
    {
      message_vision("$N推开一堆野草，往地下钻了进去。\n", me);
      me->move(__DIR__"shanlu2");
      message_vision("$N走了过来。\n", me);
      return 2;
    }
  return ::valid_leave(me, dir);
}
