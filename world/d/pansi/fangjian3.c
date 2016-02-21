// 白骨洞
// by lestat 2001
#include <ansi.h>;
inherit ROOM;

void create()
{
        set("short", HIW"白骨洞"NOR);
        set("long", @LONG
这里阴森森的，寒气逼人，房间内四周按九宫方位摆着九堆骷髅头，每堆九
个骷髅头，下层五个，中层三个，上层
一个，模样甚是诡奇。。。。
LONG );
	set("exits", ([
		"east" : __DIR__"tongmen",
	]));
	set("objects",([
		__DIR__"npc/bai" : 1,
//		"/d/dntg/sky/npc/fengpo" : 1,
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
