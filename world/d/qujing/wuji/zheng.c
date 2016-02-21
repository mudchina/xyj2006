//    snowcat moved to /d/qujing/wuji
inherit ROOM;

void create ()
{
  set ("short", "大雄宝殿");
  set ("long", @LONG

大雄殿正中供着的乃是观音普度南海之相，其态度安详宁静，维妙
维肖。两边是其他的一些佛祖塑像，分排站立，神态各异。殿里香
烟缭绕，气氛静谧。

LONG);

  set("objects", ([ /* sizeof() == 1 */
    __DIR__"npc/monk1" : 1,
  ]));
  set("exits", ([ /* sizeof() == 3 */
    "east" : __DIR__"eastroom.c",
    "south" : __DIR__"piandian.c",
    "west" : __DIR__"westroom.c",
  ]));

  setup();
}
