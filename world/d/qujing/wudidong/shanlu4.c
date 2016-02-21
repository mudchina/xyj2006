// Room: /d/qujing/wudidong/shanlu4.c

inherit ROOM;

void create ()
{
  set ("short", "黑松林");
  set ("long", @LONG

四下里古松参天，遮天蔽日，林中光线很暗。山风吹过，只听松涛阵
阵，如低鸣，似哀哭。这里不仅绝无人迹，连野兽也不见一只，你越
走越是毛骨悚然。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "westup" : __DIR__"dong",
  "northdown" : __DIR__"shanlu3",
]));
  set("outdoors", 1);

  setup();
}
