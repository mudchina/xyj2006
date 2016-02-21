// nancheng_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("南城客栈留言板", ({ "board" }) );
	set("board_id", "nancheng1");
	set("long",	"这是一个供人留言记事的留言板。\n" );
	setup();
	set("capacity", 200);
	replace_program(BULLETIN_BOARD);
}
