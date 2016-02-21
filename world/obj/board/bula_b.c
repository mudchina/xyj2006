inherit BULLETIN_BOARD;

void create()
{
	set_name("没事找事", ({"board"}) );
set("location", "/u/bula/workroom");
set("board_id", "bula_b");
set("capacity", 100);
set("long", "反正说也白说。
──────────────────────────────\n");
        setup();
        replace_program(BULLETIN_BOARD);
}

