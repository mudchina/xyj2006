inherit BULLETIN_BOARD;

void create()
{
	set_name("比武留言板", ({ "board" }) );
	set("location", "/d/city/giftroom");
	set("long",	"这是一个供人记录比武大会事宜的留言板。\n" );
set("board_id", "biwuboard");
	setup();
	set("capacity", 200);
	replace_program(BULLETIN_BOARD);
}


