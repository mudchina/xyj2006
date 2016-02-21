inherit BULLETIN_BOARD;

void create()
{
set_name("留言壁", ({"wall"}) );
set("location", "/d/nanhai/gate");
set("board_id", "wall_b");
set("capacity", 100);
set("long", "一块留言壁，上面题满了来访者的留言。\n");
        setup();
        replace_program(BULLETIN_BOARD);
}

