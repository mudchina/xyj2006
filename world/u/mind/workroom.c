#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", "心房");
    set("long", @LONG
这颗心房里温暖如春。散了一些《时尚》杂志，一袋爆米花犹自发出香喷喷的
味道。仔细看，床上有几根头发，湿湿润润的，看起来很舒服。心房外写了几个
字(words)，还清清亮的。
LONG);
        set("sleep_room", 1);
        set("no_death", 1);
        set("valid_startroom", 1);
        set("exits", ([
            "down" :"/d/city/kezhan.c",
            "up" :"/d/wiz/wizroom.c",
            "city" :"/d/city/center.c",
            "longgong" :"/d/sea/gate.c",
        ]));
        set("item_desc", 
        (["words" : 
             HIC" 杜吟墨你这小子，我跟你没完。\n"NOR, 
        ]));

        replace_program(ROOM);
}
