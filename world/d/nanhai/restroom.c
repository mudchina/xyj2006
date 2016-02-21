//Cracked by Roath
// Room: /d/nanhai/restroom
inherit ROOM;
inherit "/d/wiz/no_get";

void create ()
{
  set ("short", "休息室");
  set ("long", @LONG

这里是普陀山的休息室，屋子里空荡荡的什么也没有，不知普陀
山门人弟子们是怎么样睡觉的。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"zoulang2",
]));
  set("no_fight", 1);
  set("light_up", 1);
  set("no_magic", 1);
  set("sleep_room", 1);

  setup();
}
