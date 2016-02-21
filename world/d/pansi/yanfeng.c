// 瀑布内
// by lestat 2001

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", HIC"瀑布内"NOR);
	set("long", @LONG
你眼前一亮，原来在这瀑布内别有洞天，洞外的大瀑布如玉龙悬空，滚滚而
下，尤似一张水帘挂在洞口，耳边轰聋聋的响声不绝于耳。
LONG );
	set("exits", ([
		"north" : __DIR__"gudi",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
void init()
{
	add_action("do_jump","jump");
}
int do_jump(string arg)
{
        object ob;
        int new_sen;
        ob = this_player();
        new_sen = random( ob->query("max_sen")*3 );
        if ( new_sen > ob->query("sen") ) new_sen = ob->query("sen") + 1;
        if( !arg || arg=="" ) return 0;
        if( arg != "down" )
                return notify_fail("你要往哪里跳？\n");
        tell_object(ob, HIR"你眼睛一闭，纵身一跃，向水帘跳去。。。。\n"NOR);
        message("vision", NOR"只见" + ob->query("name") + "眼睛一闭，纵身向水帘跳去。。。。\n"NOR, environment(ob), ob);
        if((ob->query_skill("dodge",1)<30)){ ob->unconcious();
        ob->receive_damage("sen",new_sen);
        ob->move(__DIR__"yanfeng");
		}else{
           ob->move(__DIR__"pubu");
        }
        return 1;
}
