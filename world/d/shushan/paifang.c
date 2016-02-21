#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "迎客牌坊");
        set("long", 
"威严的石牌坊，不知道什么时候修建的\n"+
"石柱瘢痕累累，但是台阶却一尘不染，\n"+
"高大的牌坊上面飞舞着：\n"+
HIG"    蜀      山      剑      派  \n"NOR
);
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"square",
  "southdown" : __DIR__"path1",
]));

        set("objects",([
        __DIR__"npc/zhike" : 2,
        ]));
        set("no_clean_up", 0);
        set("outdoors", "xx" );

        setup();
  call_other("/obj/board/sword_b", "???");
        replace_program(ROOM);
}
