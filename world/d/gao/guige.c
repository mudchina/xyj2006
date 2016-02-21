// guige.c
#include <room.h>
inherit ROOM;

void create()
{
  set ("short", "闺阁");
  set ("long", @LONG

这里是高小姐的闺楼．室内装饰典雅，家俱全是南方运来的竹器．
墙上的一幅字画风骨颇为不俗，字体看起来也相当的漂亮．
LONG);
set("exits", ([ /* sizeof() == 4 */
"east" : __DIR__"houyuan",
"up" :__DIR__"yashi",
]));
create_door("up", "雕花竹门", "down", DOOR_CLOSED);
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}


