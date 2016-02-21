// jjf_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("功劳簿", ({ "board" }) );
        set("location", "/d/jjf/keting.c");
        set("board_id", "jjf_b");
        set("long", "这是一本薄薄的功劳簿，上面密密麻麻地记着将军府弟子所立的战功。\n" );
        setup();
        set("capacity", 100);
        replace_program(BULLETIN_BOARD);
}
