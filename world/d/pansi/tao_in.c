//2001.2.2
//lestat
#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
        set("short", HIM"桃花迷阵"NOR);
        set("long",
"这是一片"+HIM"桃花"NOR+"的海洋。四周一望无际，全是盛开的"+HIM"桃花"NOR+"。微风拂过，
落英缤纷。周围静悄悄的。东西边好像有个树丛。远处偶尔传来一声
鸟叫。往北是一片"+HIM"桃花"NOR+"林，往南远远看见几只猴子。\n"
           );
       set("exits", ([
           "south" : "/d/dntg/hgs/houshan3",
           "north" : __DIR__"tao0",
           "east" : __DIR__"taob",
           "west" : __DIR__"taoa",
       ]));
	   set("objects",([
		__DIR__"npc/xiang" : 1,
		__DIR__"obj/guo" : 3,
	]));


       set("outdoors","taohua");
       set("no_clean_up", 0);
       setup();
       replace_program(ROOM);
}

