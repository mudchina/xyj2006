// 洞内
// by lestat 2001

inherit ROOM;

void create()
{
        set("short", "金光洞");
        set("long", @LONG
这里是水帘洞的尽头，四周潮湿阴暗，洞顶四处不时有水滴落在一块岩石(stone)上，
不远处有一座莲花石座，只见一个老妇正盘膝而坐。
LONG );
	set ("item_desc", ([
		"stone" : "这块岩石光滑平整。。。。你禁不住想推(push)一下。\n"
	])  ) ;
	set("exits", ([ /* sizeof() == 2 */
		"east" : __DIR__"gudi",
	]));
	set("objects",([
		__DIR__"npc/shengmu" : 1,
	]));
	set("no_clean_up", 0);
	setup();
}

void init()
{
	add_action("do_push","push");
	add_action("do_zuan",({"zuan","enter"}));
}

int do_push(string arg)
{
	object me;
	me = this_player();
//        if((!me->query("family") || (me->query("family/family_name")!="盘丝洞")) && present("shengmu",environment(me))) 
//             return notify_fail("金灵圣母双目微张，缓缓说道：“非吾门人，不可造次！”\n");
	if (!arg||arg!="stone") return 0;
	write("你运力双臂，双手扶着一块岩石，大喝一声：“动！”\n");
       if(random((int)me->query("kar")) < 10 )
		{
                write("岩石晃动了一下，但是一晃即回。\n");
		return 1;
		};
	write("岩石缓缓转动，只转到一半，便见岩石后露出一个三尺来高的洞穴(hole)。\n");
	set("exits/north", __DIR__"yandong");
	return 1;
}

int do_zuan(string arg)
{
	object me;
	me = this_player();
	if (!me->query_temp("marks/push")) return 0;
	if ( arg != "hole") return 0;
	message_vision("$N大喜之下，也没去考虑洞中有无危险，便一闪身钻进了山洞里。\n", me);
	me->move(__DIR__"yandong");
	return 1;
}

int valid_leave(object me, string dir)
{
	if (me->query_temp("marks/push") ) me->delete_temp("marks/push");
	return ::valid_leave();
}
