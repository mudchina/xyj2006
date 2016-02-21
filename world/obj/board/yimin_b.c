// nancheng_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("移民申请板", ({ "board" }) );
	set("location", "/d/city/yimin");
	set("board_id", "yimin");
	set("long",	"这是一个供人申请移民的留言板。\n" );
	setup();
	set("capacity", 200);
	replace_program(BULLETIN_BOARD);
}


