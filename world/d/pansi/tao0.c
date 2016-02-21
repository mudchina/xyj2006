//桃花迷阵 盘丝大法限制
//lestat 2001

#include <room.h>
#include <ansi.h>

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
		"east" :  __FILE__,
		"west" :  __FILE__,
		"south" : __FILE__,
		"north" : __FILE__,
       ]));
       set("no_clean_up", 0);
       setup();
}

void init()
{
    this_player()->receive_damage("kee", 5);
    this_player()->receive_wound("kee",  5);
	this_player()->receive_damage("sen", 5);
    this_player()->receive_wound("sen",  5);
    message_vision(HIM"突然一阵桃花瓣象雨点般疾射$N！\n"NOR, this_player());
}

int valid_leave(object me, string dir)
{
        int total_steps;
        if( me->query_skill("pansi-dafa",1) >100) total_steps = 1 ; 
           else total_steps = 10;
	if ( dir == "north")
            me->add_temp("taohua/steps",1);
	if ( dir == "south")
            me->add_temp("taohua/steps",-1);
	if (me->query_temp("taohua/steps") == total_steps)
        {
     	    me->move(__DIR__"tao_in");
            me->delete_temp("taohua/steps");
            return notify_fail("你走了半天，终于走出了桃花迷阵。\n");
        } 
        if (me->query_temp("taohua/steps") == - total_steps )
        {  
            me->move(__DIR__"tao_out");
            me->delete_temp("taohua/steps");
            return notify_fail("你走了半天，终于走出了桃花迷阵。\n");
     	}
        return ::valid_leave(me,dir);
}
