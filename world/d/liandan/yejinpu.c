// By canoe 2001-06-21
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","冶金铺");
	set("long",@LONG
这是神农部落的冶金铺, 一个皮肤黝黑的铁匠正
汗流雨下地打造着不知名的物什,神农氏采集百草需
要的药锄就是这里打造的。在这里, 你能够用买到
药锄.
LONG
);
	
	set("exits", ([ /* sizeof() == 2 */
  "west": __DIR__"road2",
        
]));
 set("objects", ([
    "/d/liandan/obj/tiejiang" : 1 ,
    "/d/liandan/obj/xianguan" : random(2) ,
         ]));
 
setup();
}
