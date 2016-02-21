// 长安死牢   Beeby 7/17/2000

#include <ansi.h>

inherit ROOM;


void create ()
{
        set ("short", "长安死牢");
        set ("long", @LONG
    这里是长安城中关押重犯的地方，墙壁上沾满了血迹，远远传来犯人 
被拷打的惨叫声, 任何人进了这个地方不用再想出去了。不过墙角有些土
比较松动。
LONG);
        set("exits", 
        ([ //sizeof() == 0
        ]));
        set("no_clean_up", 0);
	set("no_escape",1);
        setup();
}

void init()
{
        add_action("do_wa", "wa");
	add_action("do_wa", "dig");
}

int do_wa(string arg)
{
	string msg;
	if (this_player()->is_busy())
	 return notify_fail("你正忙着呢!\n");
	if (this_player()->query("kee")<50)
	 return notify_fail("你已精疲力尽了，还是先休息一下吧!\n");
	this_player()->add("kee",-50);
	msg="$N蹲在地上拼命地挖土，试图挖出一点地道来。\n";
	message_vision(msg,this_player());
	call_out("do_end",3,this_player());
	this_player()->start_busy(3);	
	return 1;
}

int do_end(object me)
{
	string msg;
       int i=random(5);
	mixed* file;
	switch (i)
	{
	   case 0:
	   {
	     file=get_dir(__DIR__"*.c");
	     if (sizeof(file))
	     {
	     msg="不知挖了多长时间,$N总算挖通了一条地道。\n"+
		 "$N赶紧钻了出去。\n";
	     message_vision(msg,me);
	     msg=file[random(sizeof(file))];
	     if (msg=="ground") msg="center";
              else if (msg=="prison") msg="center";
              else if (msg=="guan") msg="center";
 	     me->move(__DIR__+msg);
	     msg="只听得哄的一声，地道又塌了。\n";
	     message_vision(msg,me);
	     if (me->query("mystartroom"))
	       me->set("startroom",me->query("mystartroom"));
	     else 
	       me->set("startroom","/d/city/kezhan");
	     break;
	     }
	   }
	   default:
	   {
	     msg="门外突然响起一阵脚步声，$N吓得赶紧把地道给填上了。\n";
	     message_vision(msg,me);
	   }
	}
	return 1;
}
