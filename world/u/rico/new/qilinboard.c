inherit BULLETIN_BOARD;

void create()
{
        set_name("麒麟留言板", ({ "board" }) );
        set("location", "/u/rico/home");
        set("long",     "这是一个给火麒麟留言的留言板。\n" );
set("board_id", "qilinboard");
        setup();
        set("capacity", 200);
        replace_program(BULLETIN_BOARD);
}
