//Cracked by Roath
// Room: /d/nanhai/chaoyindong.c
inherit ROOM;

void create ()
{
  set ("short", "潮音洞");
  set ("long", @LONG

这就是南海普陀山潮音洞，救苦救难大慈大悲观音菩萨宣讲佛
法之所在。只见观音菩萨端坐在莲花台上，微开善口，敷演大
法，宣扬正果，讲的是三乘妙典，五蕴楞严。但见那天龙围绕，
花雨缤纷。正是：禅心朗照千江月，真性清涵万里天。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"guangchang.c",
]));
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/shizhe" : 1,
  __DIR__"npc/shancai" : 1,
  __DIR__"npc/guanyin" : 1,
]));
  set("light_up", 1);

  setup();
}
