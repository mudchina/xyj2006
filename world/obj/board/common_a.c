// common_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("生死之间留言板", ({ "board" }) );
	set("location", "/d/ourhome/kedian");
	set("board_id", "common_a");
	set("long",	"写下你的感受吧？！　：（\n" );
	setup();
	set("capacity", 80);
	replace_program(BULLETIN_BOARD);
}
