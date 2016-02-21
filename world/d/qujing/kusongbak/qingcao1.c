inherit ROOM;

void create ()
{
  set ("short", "青草坡");
  set ("long", @LONG

这里的青草越来越密，眼前已无道路可循。草中偶有野兔类的
小兽跑过，发出悉悉嗦嗦的声音。
LONG);
  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"qingcao1",
  "south" : __DIR__"qingcao1", 
  "west" : __DIR__"qingcao1",
  "east" : __DIR__"qingcao1",
]));

  set("outdoors", 1);
  set("no_guo", 1);

  setup();
}

void init()
{
	add_action("do_search", "search");
}

int do_search()
{
	object where, me;
	where=this_object();
	me=this_player();

	if(me->is_busy())
		return notify_fail("你正忙着呢！\n");

	if( !where->query("guo_called") ){
		set("guo_called", 1);
		call_out("guo_grow", 900);
	}

	message_vision("$N在青草中寻寻觅觅………\n", me);
	call_out("do_find", 3, me);
	me->start_busy(3);
	return 1;
}
int guo_grow()
{
	delete("no_guo");
	return 1;
}
	
int do_find(object me)
{
	object where, guo;
	where=this_object();

	if( where->query("no_guo")){
		tell_object(me, "你什么也没发现。\n");
                return 1;
        }

	if( (int)me->query_kar() > random(1000) ){
		guo=new("/d/qujing/kusong/obj/heshouwu");
		guo->move(where);
		set("no_guo", 1);
		tell_object(me, "你突然看见了一株何首乌。\n");
		return 1;
	}

	tell_object(me, "你什么也没发现。\n");
	return 1;
}
