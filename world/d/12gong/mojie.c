// by HAPP@YSZZ

inherit ROOM;
int block_cmd(string);
void create ()
{
        set ("short", "第十宫山羊座");
        set ("long",             @LONG
牧神潘恩是众神传信天使─汉密斯的儿子，他的相貌异常奇特，有着山羊角、蹄及胡子
，他是个非常优秀的音乐家。由于潘恩能演出美妙的音乐带给众神欢乐，所以他常受被邀请
到宴会中助兴。有一次，他应邀参加并为众神们吹奏时，大怪物提风突然出现并大肆倒乱。
提风横冲直撞闯入宴会，众神们都纷纷走避。潘恩在慌忙中也化作鱼跳入尼罗河中，因为太
过紧张的关系，只有下半身变成鱼尾，而上半身仍旧还是山羊的模样。这就成了半鱼半羊的
山羊座。
LONG);
        set("exits", ([
        "westup"    :       __DIR__"mj2bp1",
        "northdown"  :       __DIR__"rm2mj2",        
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/mojie" : 1,
        ]));
        set("outdoors", "12gong");
        setup();
}

int valid_leave(object me, string dir)
{
        if ( present("mo jie") && dir == "westup" )
        return notify_fail("修罗伸手拦住你道:先过我这关再说！\n");
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
