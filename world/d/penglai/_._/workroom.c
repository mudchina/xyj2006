#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", "山中小亭");
    set("long", 
"这里是一叶知秋工作的地方:\n\n"
HIY "           秋风瑟瑟\n"
    "           落叶飘飘\n\n"
HIG "电子信箱:vikee@hanwang.com.cn / vikee@263.net\n\n" NOR
);
        set("exits", ([
            "down" :"/d/city/kezhan.c",
        ]));
        replace_program(ROOM);
}
