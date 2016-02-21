// xueshan_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("		—©…Ω¡Ù—‘∞Â", ({ "wall" }) );
        set("location", "/d/xueshan/restroom.c");
        set("board_id", "xueshan_b");
        set("long",     "—©…Ω¡Ù—‘∞Â°£\n" );
        setup();
        set("capacity", 80);
        replace_program(BULLETIN_BOARD);
}

