// Room: /d/qujing/wudidong/smithy.c

inherit ROOM;

void create()
{
	set("short", "铁匠铺");
	set("long", @LONG

这里就是村里的打铁铺了。张铁匠是祖传三代的手艺，手下打出来的
铁器往往比人的寿命还长，手艺既好，活儿就多，天天从早忙到晚。
屋子一边摆着生铁和折断了的工具，另一边摆满了做好的铁器，都是
些村中必需的东西。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"road2",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/smith.c" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
