//sgzl
inherit ROOM;

void create ()
{
	set ("short", "雪阶");
	set ("long", @LONG

路又到了尽头，翻(jump)过前面的石壁(shi bi)就可进入
雪山的第三重山了。
LONG);


	set("exits", 
	([ //sizeof() == 4
                "south" : __DIR__"wuchang-n",
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
           message_vision("$N脚下一划，身不由自主的向後摔去。\n",me);
           me->unconcious();
          }
	else
          {
           me->add("kee",-50); 
           message_vision("$N纵身一跃，轻巧的翻过石壁。\n",me);
           me->move("/d/xueshan/shanpo");
           tell_room(environment(me),"只见"+me->name()+"飞身跃了上来。\n", me);
           return 1;
           }
        return 1;
}

