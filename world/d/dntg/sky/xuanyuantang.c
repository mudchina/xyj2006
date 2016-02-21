//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "轩辕堂");
set("long", @LONG
    
一座宽敞明亮的大堂，四通八达，四壁龙飞凤舞，
装饰豪华，一队队持刀悬剑的卫士从这里走来走去
好不威风．
.
LONG );


set("exits", ([
"west"   : __DIR__"baihudian",
"east"   : __DIR__"qinglongdian",
"north"   : __DIR__"xianwudian",
"south"   : __DIR__"zhuquedian",
]));


set("objects", ([
]));


setup();
}
