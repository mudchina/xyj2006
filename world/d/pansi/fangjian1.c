// fangjian1.c
// by lestat/2001.1.31

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", CYN"青云轩"NOR);
        set("long", @LONG
可以看出这里以前曾经是一个下棋的地方，房间除了一张石几，两只软
椅之外，空荡荡的一无所有，石几上刻着纵横十九道棋路，棋局上布着
几颗棋子，竟然是一局刚开始下的棋。
LONG );
	set("exits", ([
		"south" : __DIR__"shiji1",
	]));
        set("objects",([
//                "/d/dntg/sky/npc/yuntong" : 1,
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
