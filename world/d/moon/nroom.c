//Cracked by Roath
// Room: /moon/nroom.c
//cglaem...12/13/96.

inherit ROOM;

void create ()
{
  set ("short", "议事厅");
  set ("long", @LONG

刚入正厅，便觉一缕砭人肌体的冷香迎面袭来。正厅虽大，却只有几只椅
子和一张茶几，一色均是竹制，配上淡青色云石地砖，给人一种冷冷的感
觉。西首的墙上挂  着一幅水墨画房中央一盏香炉，其香幽韵而无烟，闻
之令人心骨皆清。
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/magu.c" : 1,
]));
  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"xiaoyuan",
]));

  setup();
}






