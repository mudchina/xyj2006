inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", HIG"阵口"NOR);
        set("long", @LONG
这就是入口了，没有一定的修为，最好还是不要乱闯哦。
LONG);
        set("exits", ([
                "north" : __DIR__"fenghou",
                "south" : __DIR__"xiaolu1",
        ]));
        set("objects", ([
                __DIR__"npc/guard1" : 2,
        ]));
        setup();
}
int valid_leave(object me, string dir)
{
        object a;
   if (dir == "north" ) {
                if(objectp(a=present("guard", environment(me))) &&
living(a) )
        return notify_fail("守卫拦住你说道：进阵以后就不能走出来了，还是不要进去为好。\n");
        }   
        return ::valid_leave(me, dir);
}
