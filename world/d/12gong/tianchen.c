// by HAPP@YSZZ

inherit ROOM;
int block_cmd(string);
void create ()
{
        set ("short", "第七宫天秤座");
        set ("long",
             @LONG
此乃正义女神亚斯托雷斯在为人类做善恶裁判时所用的天秤，亚斯托雷亚一只手持秤
，一只手握斩除邪恶的剑。为求公正，所以眼睛皆蒙着。从前的众神和人类是和平共处于
大地上，神虽拥有永远的生命，但人类寿命有限。因此寂寞的神只有不断创造人类，然而
那时的人号好争斗，恶业横行，众神在对人类失望之余回到天上。只有亚斯托雷斯女神舍
不得回去而留在世界上，教人为善。尽管如此，人类仍继续堕落，于是战争掀起，开始了
打打杀杀。最后连亚斯托雷斯也放弃人类而回到天上。而天空就高挂着钟爱正义和平公正
的天秤座。


LONG);


        set("exits", ([
        "southup"    :       __DIR__"tc2tx1",
        "westdown"  :       __DIR__"sn2tc2",        
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/tiancheng" : 1,
        ]));
        set("outdoors", "12gong");
        setup();
}

int valid_leave(object me, string dir)
{
        if ( present("tian chen") && dir == "southup" )
        return notify_fail("童虎笑道:先过我这关再说！\n");
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
