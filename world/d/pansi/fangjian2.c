// 桃花阁 春三十娘卧室
// by lestat
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIM"桃花阁"NOR);
        set("long", 
"这是桃花娘子的卧房，屋内挂满"+HIM"蜘蛛网"NOR+"，蛛网上粘着不少"+HIM"桃花"NOR+"，整个房间芬
芳扑鼻，偶尔有一两片"+HIM"桃花"NOR+"从蛛网上飘落，煞是好看。\n"
             );
       set("exits", ([
               "south" : __DIR__"shiji2",
       ]));

	    set("objects",([
		__DIR__"npc/niang" : 1,
	]));
	
       set("no_clean_up", 0);
       setup();
}

void init()
{
        add_action("do_han", "han");
}

int do_han(string arg)
{
	object me;
	me = this_player();

	if( !arg || arg=="" ) return 0;

	if( arg=="芝麻开门") 
	{
		tell_object(me,"你对着墙壁大喝一声：“芝麻开门！”\n");
		message("vision", "过了一会儿，你只听到一阵轰隆隆的响声，出现了一道暗门。\n", me);
		set("exits/down", __DIR__"shishi4");
		remove_call_out("close");
		call_out("close", 5, this_object());
		return 1;
	}
}

void close(object room)
{
	message("vision","一阵轰隆隆的响声过后，石门又缓缓地关上了。\n", room);
	room->delete("exits/down");
}
int valid_leave(object me,string dir)
{
        if(dir=="down" && (!me->query("family") || (me->query("family/family_name")!="盘丝洞")) && present("niang",environment(me))) 
             return notify_fail("春三十娘一个闪身，挡住了你的去路！\n");
        return ::valid_leave(me,dir);
}
