// Room: /u/none/newtoy/cave
inherit ROOM;

void create ()
{
  set ("short", "水帘洞");
  set ("long", @LONG

　　乃是一座石房。房内有石窝、石灶、石碗、石盆、石床、石凳。
中间一块石碣(stone)。但见：

　　刮风有处躲，下雨好存身。霜雪全无惧，雷声永不闻。
　　烟霞常照耀，祥瑞每蒸熏。松竹年年秀，奇花日日新。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"ironbridge",
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "stone" : "
　　　　花果山福地，水帘洞洞天。

",
]));

  setup();
}
