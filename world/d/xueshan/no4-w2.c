//sgzl
inherit ROOM;

void create ()
{
	set ("short", "雪岭");
	set ("long", @LONG

雪岭上有几处的雪被人翻开了，不知埋(mai)了什么东西进去。
传说这附近有百足蜈蚣出没，看来要小心些。
LONG);


	set("exits", 
	([ //sizeof() == 4
                "east" : __DIR__"no4-w1",
                "north" : __DIR__"no4-wn2",
	]));
	
	set("objects", 
	([
	]));


        set("have_ji",0);

	set("outdoors", "xueshan");

	setup();
}

void init()
{
        add_action("do_mai", "mai");
}


int do_mai(string arg)
{       
        object me=this_object();
        object who=this_player();
        object ji;

        if ( !arg && (arg != "gong ji") && (arg != "ji"))
                return notify_fail("你要埋什么？\n");

        ji=present("gong ji", who);
        if (! present(arg, who)) 
            return notify_fail("你身上没有这东西。\n");

        if ( me->query("have_ji") )
                return notify_fail("这已经埋了一大堆乱七八糟的东西了，别再污染雪山的风景了。\n");

        me->set("have_ji",1);
        message_vision("$N将一只公鸡埋进了雪里。\n",who);
        destruct(ji);
        call_out ("wugong",10+random(10),who);
        return 1;
}


void wugong (object who)
  {
    object wugong;
    message_vision("一只百足蜈蚣爬到了过来。\n",who);
    wugong=new("/d/xueshan/npc/wugong");
    wugong->move(this_object());
  }
