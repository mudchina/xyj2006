//sgzl
inherit ROOM;

void create ()
{
	set ("short", "雪阶");
	set ("long", @LONG

上山的路到这里断了，前面是一座石壁(shi bi)，石壁并不甚高，
看来跳(jump)上去并不困难。
LONG);


	set("exits", 
	([ //sizeof() == 4
                "south" : __DIR__"xuelu",
	]));
	
	set("objects", 
	([
	]));


	set("outdoors", "xueshan");

	setup();
}

void init()
{
        add_action("do_jump", "jump");
}


int do_jump(string arg)
{       
        object me;
        me=this_player();

        if ( !arg || ((arg != "shi bi") ))
                return notify_fail("你要往哪跳？\n");
        else if(me->query("kee")<50)   
          {
           me->unconcious();
           message_vision("$N脚下一划，身不由自主的向後摔去。\n",me);
          }
	else
          {
           me->add("kee",-50); 
           message_vision("$N纵身一跃，轻巧的跳上石壁。\n",me);
           me->move("/d/xueshan/wuchang-s");
       //    tell_room( environment(me),"只见$N飞身跃了上来。\n",me);
           tell_room(environment(me),"只见"+me->name()+"飞身跃了上来。\n", me);
           return 1;
           }
        return 1;
}

