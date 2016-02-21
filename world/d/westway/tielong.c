inherit ROOM;
#include <ansi.h>

#include <ansi.h>


void create ()
{
  set ("short","铁笼中");
  set ("long", @LONG

铁笼是由手指粗的钢条圈成，看起来十分的坚固。一般人看来
是休想逃出去的，不过你也可以去试试扳开(break)它。
LONG);

  set("exits", ([
//        "southeast" : __DIR__"yinma",
      ]));

  setup();
}

void init()
{
	add_action("do_break", "break");
}

int do_break()
{
	object me=this_player();
	int i;
	i=(int)me->query("force_factor")*5 + (int)me->query("str");

	if( this_object()->query("open") )
		return notify_fail("铁笼已经打开了，别费劲了。\n");

	message_vision("$N扯着铁栏杆，双手一较劲，大喊一声“开！”\n", me);
	
	if( i > 300)
		tell_room(this_object(), "只听铁栏杆发出“咔，咔”的响声………\n");
	else if( i > 200)
		tell_room(this_object(), "只见铁栏杆慢慢变弯………\n");
	else if( i > 100)
		tell_room(this_object(), "铁栏杆好象被扳弯了一些………\n");
	else
		tell_room(this_object(), "铁栏杆好象没有什么动静………\n");

	this_object()->add("break", i);
	me->receive_damage("kee", 30);
	me->add("force", -(int)me->query("force_factor"));
	
	if( (int)me->query("force") < 0 ){
		me->set("force", 0);
	}

	if ( (int)this_object()->query("break") > 3000 ){
		tell_room(this_object(),"铁栏杆的缝隙足够一个人钻出去了。\n");
		this_object()->set("open", 1);
		set("long", @LONG

一个破烂不堪的铁笼，扭曲的栏架让出的空隙正好可以让一个人
钻出去。
LONG);
		this_object()->set("exits/out", "/d/westway/lu1");
	}
	return 1;
}

int valid_leave(object me, string dir)
{
        if (dir == "out" ) {
		if( !this_object()->query("exits/out"))
			return notify_fail("这个方向没有出路。\n");
		message_vision("$N躬身从铁笼中钻了出去。\n", me);
		return 1;
        }   
	
}




