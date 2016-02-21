// moon_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("∑„—©ÃÏµÿ¡Ù—‘∞Â", ({ "board" }) );
        set("location", "/d/moon/fengxue/living.c");
        set("board_id", "fxtd_b");
        set("long",     "∑„—©ÃÏµÿ¡Ù—‘∞Â°£\n" );
        setup();
        set("capacity", 80);
        replace_program(BULLETIN_BOARD);
}

