// Room: /d/jjf/guest_shufang.c

inherit ROOM;

void create ()
{
  set ("short", "书房");
  set ("long", @LONG

踏进门来，第一眼就看见墙上的一幅淡黄卷轴，上书十四个大字：
古来青史谁不见，今见功名胜古人。四周的书架上摆满了书，春秋
战国，诸子百家，无一不有。书桌后面放着一架大理石屏风，转过
去只见窗口放着张小小木榻，往下望去，柳条垂金，群芳争艳。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"guest_cabinet2",
]));

  setup();
}
