// Room: /d/jjf/stone_road2.c

inherit ROOM;

void create ()
{
  set ("short", "石子路");
  set ("long", @LONG
小路是用五彩缤纷的石子铺成的。石子组成了各种花纹，甚是
好看。路边池塘里荷花亭亭，蜻蜓飞来飞去，只有偶尔传来的几声
蛙鸣打破了四周的宁静。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"sw_garden",
  "south" : __DIR__"main_cabinet",
]));

  setup();
}
