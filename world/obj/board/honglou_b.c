// honglou_b.c by none on 96/10/25

inherit BULLETIN_BOARD;

void create()
{
        set_name("玉石", ({ "jade" }) );
        set("location", "/d/ourhome/honglou/main.c");
        set("board_id", "honglou_b");
        set("long",     "一块玉石，可以写红楼故事。:)\n" );
        setup();
        set("capacity", 30);
        replace_program(BULLETIN_BOARD);
}

