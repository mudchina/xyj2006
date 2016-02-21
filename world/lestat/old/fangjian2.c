// fangjian2.c
// by lestat

inherit ROOM;

void create()
{
        set("short", "桃花阁");
        set("long", @LONG
这是一间布置成卧室模样的小房间，有张石床，床上摆着个小小的木头
制成的摇篮，墙壁上悬着一个七弦琴，弦线都已经断了。
LONG );
       set("exits", ([
               "south" : __DIR__"shiji2",
       ]));

	    set("objects",([
		__DIR__"npc/niang" : 1,
		"/d/pansi/obj/qin.c":1, 
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
		tell_object(me,"你气运丹田，对着墙壁大喝一声：“芝麻开门！”\n");
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
             return notify_fail("春十三娘一个闪身，挡住了你的去路！\n");
        return ::valid_leave(me,dir);
}