// nancheng_b.c

inherit BULLETIN_BOARD;

void create()
{
 set_name("新闻发布留言板", ({ "board" }) );
set("location", "/d/wiz/newsroom");
 set("board_id", "ann_b");
	set("long",	"这是一个供人留言记事的留言板。\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}
