// Room: /u/hkgroup/april
inherit ROOM;

void create ()
{
  set ("short", "四月谜会");
  set ("long", @LONG

　　黑不是，白不是，红也不是，和狐狼猫狗仿佛，既非家畜，又非野兽
　　诗也有，词也有，论语也有，对东西南北模糊，虽为短品，也是妙文

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"village",
]));
  set("outdoors", "/u/hkgroup");

  setup();
}
