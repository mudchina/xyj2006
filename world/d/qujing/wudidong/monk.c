// Room: /d/qujing/wudidong/monk.c

inherit ROOM;

void create ()
{
  set ("short", "狱中");
  set ("long", @LONG

狱里燃着盏极小的油灯，微弱的黄光中只见地上的干草堆里躺着个老
和尚，衣衫破烂，全身血迹斑斑，已被折磨得不成人形了，幸喜还没
戴手铐脚镣。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"jail",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/fangzhang-jail" : 1,
]));
  set("outdoors", 0);
  setup();
}
