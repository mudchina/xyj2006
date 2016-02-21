// pickle's board.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("黑板", ({ "chalkboard" }) );
	set("location", "/u/pickle/workroom");
	set("board_id", "chalkboard");
	set("long",	"这是一面脏脏的黑板，上面写满了杂乱无章的留言。\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}
