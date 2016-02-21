// by HAPP@YSZZ
#include <ansi.h>

inherit ROOM;
int block_cmd(string);
void create ()
{
        set ("short", "第二宫金牛座");
        set ("long", @LONG
    经希腊哈莫尼亚地方的贝纳斯河，国王贝纳斯有位美丽的公主赫洛蓓。有一天，
公主和侍女们到野外摘花，玩耍，突然出现一只如雪花般洁白的牛，以级温柔的眼光望着
赫洛蓓，其实这只牛是仰慕公主美色的宙斯变的。一开始公主的确大吃一惊，但仍走向温
驯的牛只身旁，轻轻抚摸它。由于公牛显得非常乖巧而温驯，于是公主就放心的爬到牛背
上试骑，忽然间牛奔跑了起来，最后跳进爱琴海。公主紧抱着牛，海里生物皆出来向宙斯
行礼，公主终于知道牛是宙斯的化身，到了克里特岛后，就和宙斯举行婚礼，化身为牛的
宙斯和赫洛蓓公主过着幸福的日子。

LONG);


        set("exits", ([
        "westup"    :       __DIR__"jn2sz1",
        "northdown"  :       __DIR__"by2jn2",        
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/jinniu" : 1,
        ]));
        set("outdoors", "12gong");
        setup();
}

int valid_leave(object me, string dir)
{
        if ( present("aldebaran") && dir == "westup" )
        return notify_fail("亚鲁迪巴冷笑道:先过我这关再说！\n");
        return ::valid_leave(me, dir);
}

void init()
{
    add_action("block_cmd", "", 1);
}
int block_cmd(string args)
{
string verb;
verb = query_verb();
    if (verb == "recall") return 1;
    return 0;
}
