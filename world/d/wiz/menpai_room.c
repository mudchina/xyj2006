// Room: /d/wiz/menpai_room
inherit ROOM;

void create ()
{
  set ("short", "门派讨论室");
  set ("long", @LONG

这里是供西游记巫师们讨论门派发展平衡等各种问题的。
LONG);
/*
西游记现有门派如下：

仙：南海普陀，方寸灵台
妖：陷空山无底洞，大雪山
中：将军府，月宫，龙宫，地府
*/

  set("no_fight", 1);
  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"jobroom",
]));
  set("light_up", 1);
  set("no_magic", 1);

  setup();
  call_other("/obj/board/menpai_bbs", "???");
}
