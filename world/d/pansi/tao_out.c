//桃花迷阵
//lestat 2001
#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
        set("short", HIM"桃花迷阵"NOR);
        set("long",
"这是一片"+HIM"桃花"NOR+"的海洋。四周一望无际，全是盛开的"+HIM"桃花"NOR+"。微风拂过，
落英缤纷。周围静悄悄的。远处偶尔传来一声鸟叫。往南是一片桃
花林，往北远方遥遥听见轰轰隆隆的水声,似乎有个"+HIC"瀑布"NOR+"。\n"
 );
       set("exits", ([
           "south" : __DIR__"tao0",
           "north" : __DIR__"pubu",
       ]));
       set("outdoors","taohua");
       set("no_clean_up", 0);
       setup();
}
