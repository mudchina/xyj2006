// /clone/board/bonze_b.c

#include "ansi.h"

inherit BBS_BOARD;

void create()
{
	set_name("西游记发展讨论板", ({ "board" }) );
	set("location", "/d/wiz/entrance");
	set("board_id", "query_bbs");
	set("long", "这是一个供巫师及玩家讨论发展建设用的讨论板。\n" );
	setup();
	set("capacity", 300);
	replace_program(BBS_BOARD);
}

