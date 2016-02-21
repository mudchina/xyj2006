// by HAPP@YSZZ
#include <ansi.h>
inherit ROOM;
int block_cmd(string);
void create ()
{
        set ("short", "第四宫巨蟹座");
        set ("long", @LONG
    宙斯和人间女孩阿克梅妮生了儿子海格拉斯，海格拉斯后来和德贝的公主结婚，生了
小孩过着美满的生活。由于宙斯正后赫拉的咒语，海格拉斯竟亲手刃妻，自己也正欲自杀
，宙斯为了让他赎罪，乃任命为耶里斯特斯王，他必需经历十二大冒险行动，其中第二项
是制服住在沼泽中的怪物西多拉。西多拉是只有九个头的巨蛇，躲在沼泽附近的洞窟内，
海格拉斯对其投火炬，激怒的西多拉乃吐毒气攻击，同住在沼泽里的大巨蟹眼见西多拉苦
战，乃跳出咬海格拉斯的脚，结果巨蟹被踩碎，西多拉也被制服。赫拉因感伤它的逝世，
而在天上设立巨蟹座。

LONG);


        set("exits", ([
        "eastup"    :       __DIR__"jx2sz1",
        "southdown"  :       __DIR__"sz2jx2",        
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/juxie" : 1,
        ]));
        set("outdoors", "12gong");
        setup();
}

int valid_leave(object me, string dir)
{
        if ( present("ju xie") && dir == "eastup" )
        return notify_fail("迪斯马斯克:先过我这关再说！\n");
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
