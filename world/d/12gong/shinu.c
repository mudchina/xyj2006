// by HAPP@YSZZ

inherit ROOM;
int block_cmd(string);
void create ()
{
        set ("short", "第六宫处女座");
        set ("long", @LONG
    农业女神得墨特尔和宙斯大帝育有一女普西芬妮，有一天普西芬妮在野地摘花时，有
朵从为见过的美丽花朵正盛开着，正当她伸手要摘时，地面突然裂成好几块，就掉下去了
。母亲得墨特尔誓死也要找回失踪的女儿而四处寻访。看到所有事情经过的太阳神赫利俄
斯乃告诉得墨特尔，因冥王海德斯欲娶普西芬妮为妻，而将她带回地下，得墨特尔因为悲
伤过度而使植物枯萎，大地一毛不生。宙斯看事态严重，乃向海德斯说情，可是海德斯在
普西芬妮要走时，拿了冥界石榴给她吃，普西芬妮因为可以离开，高兴吃了四个，结果被
迫一年有四个月要留在冥界，这四个月就变得今日万物不宜耕种的冬天，普西芬妮一回到
人间就是春天，得墨特尔就是处女座的化身。

LONG);


        set("exits", ([
        "westup"    :       __DIR__"sn2tc1",
        "northdown"  :       __DIR__"sz2sn2",        
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/shinu" : 1,
        ]));
        set("outdoors", "12gong");
        setup();
}

int valid_leave(object me, string dir)
{
        if ( present("shi nu") && dir == "westup" )
        return notify_fail("沙加摇了摇头：想见到女神,先过我这关再说！\n");
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
