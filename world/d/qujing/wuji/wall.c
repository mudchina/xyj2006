// Room: /u/mimi/zhuziguo/wall.c  snowcat moved to /d/qujing/wuji
inherit ROOM;

void create()
{
  set ("short", "宫墙外围");
  set ("long", @LONG

这里是王宫的宫墙外围，高大的墙壁乃是青石垒成，十分结实整齐。
宫墙上方有一个哨亭角楼。

LONG);

  set("exits", ([ /* sizeof() == 1 */
    "north" : __DIR__"hzm",
    "east" : __DIR__"wall2",
  ]));
  set("objects", ([ /* sizeof() == 1 */
    __DIR__"npc/weishi" : 2,
  ]));
  set("outdoors", __DIR__"");                   
  setup();
}

int valid_leave (object who, string dir)
{
  object shi = present ("wei shi", environment(who));
  if (dir == "north" && shi && living (shi))
      return notify_fail (shi->query("name")+"喝道：禁行！\n");
  return ::valid_leave(who, dir);
}
