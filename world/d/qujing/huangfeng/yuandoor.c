// created by wxb 12/24/1998
// room: /d/qujing/huangfeng/yuandoor.c
#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
	set ("short", "园门");
	set ("long", @LONG

一扇小铁门。门上写着“后园”二字。门前守卫森严。你注意
到门上挂着一块大锁，看来想进去极为不易。

LONG);

	set("exits", 
	([ //sizeof() == 4
		"southwest" : __DIR__"ting",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		__DIR__"npc/shoumenyao" : 2,
	]));

	setup();
}
int valid_leave(object me, string dir)
{
  if (dir == "north" && 
      member_array("hu xianfeng",me->parse_command_id_list())==-1)
    return notify_fail("你以为谁都可以随便出入后园吗?\n");
  return ::valid_leave(me, dir);
}

void init()
{
        add_action("do_open", "open");
}

int do_open(string arg)
{
        object me, key, nroom;

        me = this_player();

        if( !arg || arg != "door" ) 
                return notify_fail("你要打开什么？\n");

        if( !(key = present("jin yaoshi", me)) ) 
                return notify_fail("没有钥匙怎么开门？\n");

        //now we are ready to open...
        if( !(nroom = find_object(__DIR__"yuan")) )
                nroom = load_object(__DIR__"yuan");

//        set("exits/north", __DIR__"yuan");
//        nroom->set("exits/south", __FILE__);
        message_vision("$N拿出"+HIY+"金钥匙"+NOR+"，打开铁门, 轻轻走进了后园。\n", me );
	me->move(nroom);
        me->set_temp("used_huangtong_key", 1);
        destruct(key);
        return 1;
}
