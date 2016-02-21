#include <room.h>
inherit ROOM;

void create()
{
set("short", "老君炉");
set("long", @LONG
    
这里就是太上老君炼丹的所在。屋子正中是一只一人多高的
紫色丹炉，看不出是用什么材料做的。炉下烈火熊熊，然而
你却感受不到一丝炎热。墙角焚着一炉檀香，一丝若有若无
的幽香满室缭绕。

LONG );


set("exits", ([
]));

     set("objects", ([ /* sizeof() == 4 */
     __DIR__"npc/tai" : 1,
]));


setup();
}
