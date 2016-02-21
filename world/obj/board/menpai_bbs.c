// /clone/board/bonze_b.c

#include "ansi.h"

inherit BBS_BOARD;

void create()
{
	set_name("西游记"+HIG+"门派"+NOR+"讨论板", ({ "board" }) );
	set("location", "/d/wiz/menpai_room");
	set("board_id", "menpai_bbs");
	set("long", "这是一个供巫师们讨论门派发展建设用的新闻板。\n" );
	setup();
	set("capacity", 30);
	replace_program(BBS_BOARD);
}
