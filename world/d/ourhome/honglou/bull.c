// Room: /u/hkgroup/bull
inherit ROOM;

void create()
{
  set ("short", "菩提明镜");
  set ("long", @LONG

　　　　菩提本非树，明镜亦非台。

LONG);

  set("outdoors", "/u/hkgroup");
  set("exits", ([ /* sizeof() == 1 */
  "frontyard" : __DIR__"yard3",
]));
  set("no_clean_up", 1);
  setup();
}
