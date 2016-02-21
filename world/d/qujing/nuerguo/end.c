// created by snowcat.c 4/4/1997
// room: /d/nuerguo/changshi.c

inherit ROOM;

void create ()
{
  set ("short", "一线天");
  set ("long", @LONG

你来到一个峡谷底，两壁是高高的山崖，崖顶云雾缭绕，阳
光照不进来。左前方有一丈许高的灵石，上刻着三个大字：
经纬石。灵石荧荧地发着罕见的霞光。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"changbie",
  "northwest" : "/d/qujing/dudi/shanlu9",
]));

  setup();
}

int valid_leave (object me, string dir)
{
  object queen;

/*
  if (dir=="northwest" && 
      me->query("obstacle/nuerguo") != "done")
  {
    queen = new (__DIR__"npc/queen");
    queen->stop_access (me);
    //destruct (queen);
    return notify_fail("看样子过不去。\n");
  }
*/
  return 1;
}
