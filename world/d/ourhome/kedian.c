// Room: /d/ourhome/kedian.c

inherit ROOM;

void reset();
void create()
{
	set("short", "荒郊小店");
	set("long", @LONG

这是一家不知名的荒郊小店，四壁早已破败，不知道为什么生意
仍然非常兴隆。一帮酒客在此聊得天花乱坠。店小二更是里里外
外忙得团团转，接待着南腔北调的客人。    
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/xiaoer" : 1,
]));
//	set("valid_startroom", 1);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"kedian2",
]));
	set("no_fight", 1);
	set("no_magic", 1);
	set("no_clean_up", 0);

	setup();
	"obj/board/common_a"->foo();
	replace_program(ROOM);
}
