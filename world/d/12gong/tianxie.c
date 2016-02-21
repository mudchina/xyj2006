// by HAPP@YSZZ

inherit ROOM;
int block_cmd(string);
void create ()
{
        set ("short", "第八宫天蝎座");
        set ("long",@LONG
在古希腊时代，海神波塞顿的儿子奥立安是位有名的斗士，不仅是美少年，又是有强
健体魄的男子，所以相当有女人缘。他本身也相当自豪，还曾大言不惭的公告天下：世界
上没有比我更棒的人！赫拉女神听到后相当不悦，乃派出一只猛毒的天蝎去抓奥立安，并
放逐到原来的地方。天蝎悄巧溜到毫不知情的奥立安身边，以其毒针向其后脚跟刺去，奥
立安根本来不及有所反应，就已气绝身亡。因为有此功勋，所以天上就有天蝎座。即使现
在，只要天蝎座从东方升起，奥立安座(猎户座)就敢紧向西方地平线隐藏沉没.

LONG);
        set("exits", ([
        "eastup"    :       __DIR__"tx2rm1",
        "southdown"  :       __DIR__"tc2tx2",        
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/tianxie" : 1,
        ]));
        set("outdoors", "12gong");
        setup();
}

int valid_leave(object me, string dir)
{
        if ( present("tian xie") && dir == "eastup" )
        return notify_fail("米罗冷笑道:先过我这关再说！\n");
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
