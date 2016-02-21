// Room: /d/qujing/wudidong/shanlu2.c

inherit ROOM;

void create()
{
  set("short", "山腹");
  set("long", @LONG

四处黑沉沉的，什么也看不清，只能摸索着前进。地面颇为潮湿，霉
气扑鼻。两边壁上都是凹凸不平的尖石，脚下也是时高时低。南边有
一线微弱的亮光，不知是不是快到洞口了。
LONG);
  set("exits", ([ /* sizeof() == 2 */
		 "northeast" : __DIR__"shanlu1",
		 "southup" : __DIR__"shanlu3.c",
		 ]));
  set("no_clean_up", 0);
  setup();
}
int valid_leave(object me, string dir)
{
  if (dir == "southup")
    {
      message_vision("$N往南边离开。\n", me);
      me->move(__DIR__"shanlu3");
      message_vision("$N推开一堆野草，从地下钻了出来。\n", me);
      return 2; // return 2 to avoid "go" to show other messages. mon
    }
  return ::valid_leave(me, dir);
}
