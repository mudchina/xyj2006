// Room: /u/mimi/zhuziguo/ziyun.c    snowcat moved to /d/qujing/wuji
inherit ROOM;

void create ()
{
  set ("short", "紫云宫");
  set ("long", @LONG


此乃王后的寝宫。国王王后曾经非常恩爱，所以国王经常在此留宿。
这三年来国王不知什么原因慢慢冷落了王后。宫中虽然陈设华丽，
但冷冷清清的，一个人也没有。

LONG);

  set("exits", ([ /* sizeof() == 1 */
    "east" : __DIR__"huilang2",
  ]));

  setup();
}
