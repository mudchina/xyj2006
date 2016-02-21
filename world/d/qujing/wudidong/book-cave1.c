// Room: /d/qujing/wudidong/book_cave1
// created 9-15-97 pickle

/************************************************************/
#include <ansi.h>
inherit ROOM;
int valid_leave(object me, string dir);

/************************************************************/
void create ()
{
  set ("short", "洞穴");
  set ("long", @LONG

这里遍地都是尘土，显然很少有人来往。洞中有些微弱的烛光，更加
显得阴森恐怖。角落里似乎有个人影，你不由得一阵紧张。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "northdown" : __DIR__"book-cave2.c",
  "up" : __DIR__"weaponry",
]));

  setup();
}

/************************************************************/
int valid_leave(object me, string dir)
{
    object guard, here=this_object();
    object *inv, container;
    int sizeinv;

    if (dir == "up")
	me->delete_temp("wudidong/gave_bookguard_baozi");
    if (dir != "northdown")
	return ::valid_leave(me, dir);
    if (dir == "northdown"
     && objectp(guard=present("ku lou", here)))
    {
//        if (me->query("wudidong/last_entered_book_cave") + 3600 > time())
//        {
//                message_vision(CYN"骷髅阴阴地说道：你这个混帐！进进出出的有完没完？待会儿那个绿毛老鼠要是知道了，叫你吃不了兜着走！\n"NOR, me);
//                return notify_fail("");
//        }
	inv=all_inventory(me);
	sizeinv=sizeof(inv);
	while (sizeinv--)
	{
	    if (userp(inv[sizeinv]))
	    {
		container=inv[sizeinv];
		break;
	    }
	    if (inv[sizeinv]->is_container())
	    {
		container=inv[sizeinv];
		break;
	    }
	    continue;
	}
	if (container)
	{
	    message_vision(CYN"骷髅阴阴地说道：你带着那"+container->name()+
			   CYN"进去干什么！？被那绿毛老鼠看见了怎么办！？\n"NOR,me);
	    return notify_fail("");
	}
    }

    if (objectp(guard=present("ku lou", here)))
    {
	if (me->query_temp("wudidong/gave_bookguard_baozi"))
	{
	    message_vision(CYN"骷髅阴阴地说道：快点出来，要是给那绿毛老鼠发现了就热闹了！\n"NOR, me);
	    me->set("wudidong/last_entered_book_cave", time());
	    return ::valid_leave(me, dir);
	}
	message_vision(CYN "骷髅阴笑道：什嘛？想溜？没门！\n"NOR, me);
	return notify_fail("");
    }

    message_vision("墙脚里的人影慢慢站了起来，挡住北面的出口。\n", me);
    guard = new(__DIR__"npc/kulou");
    guard->move(here);
    return notify_fail("");

}
