// rewritten by snowcat on 4/11/1997
// room: shalu

inherit ROOM;

void create ()
{
  set ("short", "砂砾径");
  set ("long", @LONG

小径至此分岔，往西通向火焰山，西南的小道蜿蜒曲折，不知通向
何处。山上的热浪一阵阵的涌来。

LONG);

  set("exits", ([
        "westup"    : __DIR__"shanbian",
        "east"      : __DIR__"shalu2",
        "southwest" : __DIR__"wuming1",
      ]));
  set("outdoors", "firemount");

  setup();
}
