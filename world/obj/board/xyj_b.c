#include "ansi.h"

inherit BBS_BOARD;

void create()
{
        set_name("西游"+HIG+" BBS "+NOR+"新闻试用板", ({ "board" }) );
        set("location", "/d/wiz/jobroom");
        set("board_id", "xyj_b");
        set("long", "这是一个供各位交流讨论的"+HIG+" BBS "+NOR+"板。\n" );
        setup();
        set("capacity", 500);
        replace_program(BBS_BOARD);
}

