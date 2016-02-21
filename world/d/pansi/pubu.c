// pubu.c 
// by/lestat

inherit ROOM;

#include <ansi.h>
void create()
{
	set("short", "瀑布");
	set("long", @LONG
你猛听得水声响亮，轰轰隆隆，便如潮水大至一般，抬头一看，只见一
条大瀑布，犹如银河倒悬，从高崖上直泻下来。下面是万丈深渊，云雾弥漫，
望不到尽头。。。。
LONG );
	set("exits", ([ /* sizeof() == 2 */
		"south" :  __DIR__"tao_out",
	]));
                    set("objects",([
//                __DIR__"npc/qingxia" : 1,
        ]));
    set("outdoors", "pansi" );
	set("no_clean_up", 0);
	set("no_magic",1);
	setup();
}
 
void init()
{
	add_action("do_jump","jump");
	add_action("do_fly","fly");
}

int do_jump(string arg)
{
        object ob;
        int new_sen;
        ob = this_player();
        new_sen = random( ob->query("max_sen")*3 );
     	if ( present("zixia xianzi") && present("qingxia xianzi") && present("erlang zhenjun"))
	     {
             message("vision", NOR"你还是等会再跳吧．\n"NOR,ob);
			 return 1;
		 }
		if ( new_sen > ob->query("sen") ) new_sen = ob->query("sen") + 1;
        if( !arg || arg=="" ) return 0;
        if( arg != "down" )
                return notify_fail("你想要跳崖自杀？这么想不开啊？\n");
        tell_object(ob, HIR"你不加思索，纵身一跃，跳下了悬崖。。。。\n"NOR);
        message("vision", NOR"只见" + ob->query("name") + "万念俱灰，纵身跳入了悬崖之中。。。。\n"NOR, environment(ob), ob);
        if((ob->query_skill("dodge",1)<30)){ ob->unconcious();
        ob->receive_damage("sen",new_sen);
        ob->move(__DIR__"yanfeng");
		}else{
           ob->move(__DIR__"yanfeng");
        }
        return 1;
}

int valid_leave(object me, string dir)
{
	if ( present("zixia xianzi") && dir == "south" && present("qingxia xianzi") && present("erlang zhenjun"))
		           return notify_fail("等他们打完了再走吧．\n");
    return ::valid_leave(me, dir);
}





