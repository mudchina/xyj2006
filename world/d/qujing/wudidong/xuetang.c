//xuetang.c
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "学堂");
	set("long", @LONG

    张秀才胸怀大志，只可惜入京去考状元，名落孙山，白白浪费了
若干盘缠。如今只好回家来开个学堂，养家糊口。教的倒都是孔孟之
书，念的是之乎者也。一众学生们手攥树枝，正在沙盘里练写「张」
字，张秀才背着手，在屋中晃来晃去。墙上挂着一首诗 (poem)，倒
写得龙飞凤舞的。

LONG
        );

set("item_desc",(["poem":"

\t \t夏日野营有感
\t \t  张及第作

\t拔\t夜\t处\t夏
\t足\t来\t处\t眠
\t赶\t大\t蚊\t不
\t紧\t狗\t子\t觉
\t跑\t熊\t咬\t晓
\t！\t，\t。\t，
                  \n"]));

	set("exits", ([
		"south"  : __DIR__"road3",
        ]));

	set("objects", ([
		__DIR__"npc/xiucai" : 1,
		__DIR__"npc/boy" : 2,
		__DIR__"npc/girl"  : 2,
        ]));

	setup();
}
