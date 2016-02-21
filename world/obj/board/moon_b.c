// moon_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("‘¬π¨¡Ù—‘∞Â", ({ "board" }) );
      set("location", "/d/moon/xiaoyuan");
        set("board_id", "moon_b");
        set("long",     "‘¬π¨¡Ù—‘∞Â°£\n" );
set("capacity", 80);
        setup();
        replace_program(BULLETIN_BOARD);
}

