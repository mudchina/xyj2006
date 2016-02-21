//Cracked by Roath

//  妖神之争 １。０
//  by happ@YSZZ 2000.4.9
//  /d/qujing/wuzhuang/tree.c

#include <room.h>
inherit ROOM;
#include <ansi.h>

void create ()
{
   set ("short", "人参果树");
   set ("long", @LONG

这是一棵人参果树，真是个青枝馥郁，绿叶阴森，那叶儿却似芭蕉
模样，直上去有千尺多高，根下有七八丈周围，向南的枝上，露出
一个人参果，真象个孩儿一般，风过处裟裟做响。

LONG);

   set("exits", 
   ([ //sizeof() == 4
        "up" : __DIR__"shugan1",
        "south": __DIR__"baicaidi",
   ]));
   
   setup();
}

int valid_leave(object me, string dir)
{
        if ( dir == "south" && me->query_temp("kill_tree") )
                {
        tell_object(me,HIY"忽然天上伸出一个大手，一下就把你抓走了，原来是镇元大仙。\n"NOR);
        me->move("/d/qujing/wuzhuang/chengyun");
        return notify_fail(HIC"你心里暗想，这下玩了。\n"NOR);
                }
        return ::valid_leave(me, dir);
}

