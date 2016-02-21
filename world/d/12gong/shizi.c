// by HAPP@YSZZ

inherit ROOM;
int block_cmd(string);
void create ()
{
        set ("short", "第五宫狮子座");
        set ("long", @LONG
    宙斯和阿克梅妮所生之子海格拉斯，被任命为耶里斯特斯王，要去执行十二项困难的
任务，第一个任务是制服在涅梅谷的不死食人狮，这只狮子专吃家畜和村人，人人畏惧，
以前曾有人来制服，但未见生还者。来到涅梅谷的海格拉斯也是迷了路好多天，才发现狮
子的踪迹。海格拉斯欲射箭攻击，但因狮皮太硬而无效。用剑砍剑也弯掉了，于是用橄榄
树制成粗棍，用力往狮头打去，此时不怕弓剑的狮子也畏惧发怒的海格拉斯，被海格拉斯
绑住脖子，终于被他击退。女神赫拉为了感念这只狮子，乃在天上设立了狮子星座。
LONG);


        set("exits", ([
        "northup"    :       __DIR__"sz2sn1",
        "eastdown"  :       __DIR__"jx2sz2",        
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/shizi" : 1,
        ]));
        set("outdoors", "12gong");
        setup();
}

int valid_leave(object me, string dir)
{
        if ( present("shi zi") && dir == "northup" )
        return notify_fail("艾欧里亚冷笑：先过我这关再说！\n");
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
