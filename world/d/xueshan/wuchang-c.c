//standroom.c used by weiqi...others may hate this format:D
//wuchang-c.c

inherit ROOM;

void create ()
{
	set ("short", "中心武场");
	set ("long", @LONG

这是冰宫前的一块平地，供大雪山弟子练功之用。冰面极平，光
鉴照人。不过走在上面得小心点，雪山弟子也正是借此锻炼下盘
的稳固功夫。东面的一栋房子顶上一股炊烟冉冉升起，想必是厨
房了。西面是雪山弟子的休息处。
LONG);

	//set("item_desc", ([" *** " : " *** \n", ]));
	//for look something.

	set("exits", 
	([ //sizeof() == 4
		"south" : __DIR__"wuchang-s",
		"north" : __DIR__"wuchang-n",
		"west" : __DIR__"wuchang-w",
		"east" : __DIR__"wuchang-e",
		//"up" : __DIR__"***",
		//"down" : __DIR__"***",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		__DIR__"npc/xunshi" : 2,
		__DIR__"npc/yingwu-guai" : 1,
		"/d/obj/misc/ice.c" : 1,
	]));


	set("outdoors", "xueshan");

	setup();
}

void init()
{
	add_action("do_skate", "skate");
	add_action("do_skate", "huabing");
	add_action("do_skate", "hua");
}

int do_skate(string arg)
{
	int point;
	int gainfactor; //set the dodge level can be obtained by skating.
 	object me = this_player();

	gainfactor = 1;
	if( (int)me->query_skill("dodge", 1) > 50 ) gainfactor = 0;

	point = 5 + me->query("max_kee")*5/100;

	if( me->query("kee") < (int)me->query("max_kee")/4 )
	{
		message_vision("$N跳起来往冰上一滑...结果摔了个四脚朝天。\n", me);
		return 1;
	}      
	if( me->query("sen") < (int)me->query("max_sen")/4 )
	{
		message_vision("$N跳起来往冰上一滑...结果原地转了几圈，头晕之下赶忙趴在冰上，再也不敢动弹。\n", me);
		return 1;
	}      

//need construct the followwing section as another function?dunno how yet...weiqi.
	//go north.
	message_vision("$N兴高采烈，姿势优美地往北滑了过去。\n", me);
	me->move(__DIR__"wuchang-n");
	me->receive_damage("kee", point);
	me->improve_skill("dodge", (1+random(point/2))*gainfactor);
	message_vision("$N得意洋洋地从冰上冲了过来！\n", me);

	if( (me->query("kee") < (int)me->query("max_kee")/4) || 
	    (me->query("sen") < (int)me->query("max_sen")/4) ){
		message_vision("结果叭哒！一声摔了个四脚朝天！\n", me);
		return 1;
	}
//end of section 1.

//need construct the followwing section as another function?dunno how yet...weiqi.
	//go west.
	message_vision("$N兴高采烈，姿势优美地往西滑了过去。\n", me);
	me->move(__DIR__"wuchang-nw");
	me->receive_damage("kee", point);
	me->improve_skill("dodge", (1+random(point/2))*gainfactor);
	message_vision("$N得意洋洋地从冰上冲了过来！\n", me);

	if( (me->query("kee") < (int)me->query("max_kee")/4) || 
	    (me->query("sen") < (int)me->query("max_sen")/4) ){
		message_vision("结果叭哒！一声摔了个四脚朝天！\n", me);
		return 1;
	}
//end of section 2.

//need construct the followwing section as another function?dunno how yet...weiqi.
	//go south.
	message_vision("$N兴高采烈，姿势优美地往南滑了过去。\n", me);
	me->move(__DIR__"wuchang-w");
	me->receive_damage("kee", point);
	me->improve_skill("dodge", (1+random(point/2))*gainfactor);
	message_vision("$N得意洋洋地从冰上冲了过来！\n", me);

	if( (me->query("kee") < (int)me->query("max_kee")/4) || 
	    (me->query("sen") < (int)me->query("max_sen")/4) ){
		message_vision("结果叭哒！一声摔了个四脚朝天！\n", me);
		return 1;
	}
//end of section 3.

//need construct the followwing section as another function?dunno how yet...weiqi.
	//go south.
	message_vision("$N兴高采烈，姿势优美地往南滑了过去。\n", me);
	me->move(__DIR__"wuchang-sw");
	me->receive_damage("kee", point);
	me->improve_skill("dodge", (1+random(point/2))*gainfactor);
	message_vision("$N得意洋洋地从冰上冲了过来！\n", me);

	if( (me->query("kee") < (int)me->query("max_kee")/4) || 
	    (me->query("sen") < (int)me->query("max_sen")/4) ){
		message_vision("结果叭哒！一声摔了个四脚朝天！\n", me);
		return 1;
	}
//end of section 4.

//need construct the followwing section as another function?dunno how yet...weiqi.
	//go east.
	message_vision("$N兴高采烈，姿势优美地往东滑了过去。\n", me);
	me->move(__DIR__"wuchang-s");
	me->receive_damage("kee", point);
	me->improve_skill("dodge", (1+random(point/2))*gainfactor);
	message_vision("$N得意洋洋地从冰上冲了过来！\n", me);

	if( (me->query("kee") < (int)me->query("max_kee")/4) || 
	    (me->query("sen") < (int)me->query("max_sen")/4) ){
		message_vision("结果叭哒！一声摔了个四脚朝天！\n", me);
		return 1;
	}
//end of section 5.

//need construct the followwing section as another function?dunno how yet...weiqi.
	//go east.
	message_vision("$N兴高采烈，姿势优美地往东滑了过去。\n", me);
	me->move(__DIR__"wuchang-se");
	me->receive_damage("kee", point);
	me->improve_skill("dodge", (1+random(point/2))*gainfactor);
	message_vision("$N得意洋洋地从冰上冲了过来！\n", me);

	if( (me->query("kee") < (int)me->query("max_kee")/4) || 
	    (me->query("sen") < (int)me->query("max_sen")/4) ){
		message_vision("结果叭哒！一声摔了个四脚朝天！\n", me);
		return 1;
	}
//end of section 6.

//need construct the followwing section as another function?dunno how yet...weiqi.
	//go north.
	message_vision("$N兴高采烈，姿势优美地往北滑了过去。\n", me);
	me->move(__DIR__"wuchang-e");
	me->receive_damage("kee", point);
	me->improve_skill("dodge", (1+random(point/2))*gainfactor);
	message_vision("$N得意洋洋地从冰上冲了过来！\n", me);

	if( (me->query("kee") < (int)me->query("max_kee")/4) || 
	    (me->query("sen") < (int)me->query("max_sen")/4) ){
		message_vision("结果叭哒！一声摔了个四脚朝天！\n", me);
		return 1;
	}
//end of section 7.

//need construct the followwing section as another function?dunno how yet...weiqi.
	//go north.
	message_vision("$N兴高采烈，姿势优美地往北滑了过去。\n", me);
	me->move(__DIR__"wuchang-ne");
	me->receive_damage("kee", point);
	me->improve_skill("dodge", (1+random(point/2))*gainfactor);
	message_vision("$N得意洋洋地从冰上冲了过来！\n", me);

	if( (me->query("kee") < (int)me->query("max_kee")/4) || 
	    (me->query("sen") < (int)me->query("max_sen")/4) ){
		message_vision("结果叭哒！一声摔了个四脚朝天！\n", me);
		return 1;
	}
//end of section 8.

//need construct the followwing section as another function?dunno how yet...weiqi.
	//go west.
	message_vision("$N兴高采烈，姿势优美地往西滑了过去。\n", me);
	me->move(__DIR__"wuchang-n");
	me->receive_damage("kee", point);
	me->improve_skill("dodge", (1+random(point/2))*gainfactor);
	message_vision("$N得意洋洋地从冰上冲了过来！\n", me);

	if( (me->query("kee") < (int)me->query("max_kee")/4) || 
	    (me->query("sen") < (int)me->query("max_sen")/4) ){
		message_vision("结果叭哒！一声摔了个四脚朝天！\n", me);
		return 1;
	}
//end of section 9.

//need construct the followwing section as another function?dunno how yet...weiqi.
	//go south.
	message_vision("$N兴高采烈，姿势优美地往南滑了过去。\n", me);
	me->move(__DIR__"wuchang-c");
	me->receive_damage("kee", point);
	me->improve_skill("dodge", (1+random(point/2))*gainfactor);
	message_vision("$N得意洋洋地从冰上冲了过来！\n", me);

	if( (me->query("kee") < (int)me->query("max_kee")/4) || 
	    (me->query("sen") < (int)me->query("max_sen")/4) ){
		message_vision("结果叭哒！一声摔了个四脚朝天！\n", me);
		return 1;
	}
//end of section 10.

	message_vision("$N吹了声口哨，稳稳地停了下来！\n", me);
	return 1;
}

