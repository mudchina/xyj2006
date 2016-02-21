#include <room.h>
inherit ROOM;

void create()
{
        set("short", "老张家");
	set("long", @LONG

    这里就是老张的家了。显然老张一贫如洗，连把椅子都没有，只
得坐在炕上。东边支着个炉子，西边摆着各种耕田的工具，倒还齐全
。仔细看去，好像犁头断了，怪不得大白天的老张不去田里干活，坐
在家里唉声叹气。房中懒懒的睡着几只猫。你隐隐觉得有些不对：为
何村中兴养猫，而不养看家狗呢？

LONG
        );

	set("exits", ([
                "north"  : __DIR__"road3",
        ]));

	set("objects", ([
                __DIR__"npc/oldzhang" : 1,
        ]));

	setup();
}

