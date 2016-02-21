// nancheng_b.c

inherit BULLETIN_BOARD;

void create()
{
set_name("火云洞留言板", ({ "huoyun" }) );
set("location", "/d/qujing/kusong/guaishiya");
        set("board_id", "hyd_b");
	set("long",	"这是一个供人留言记事的留言板。\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}
