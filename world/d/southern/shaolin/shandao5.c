
inherit ROOM;

void create ()
{
	set ("short", "山道");
	set ("long", @LONG

少室山山势颇陡，山道却是一长列宽大的石级，规模宏伟，工程著实不小，
那是唐朝高宗为临幸少林寺而开凿，共长八里。
LONG);


	set("exits", 
	([ //sizeof() == 4
		"northdown" : __DIR__"shandao4",
		"southup" : __DIR__"simen",
		"west" : __DIR__"shuijing",
	]));
	
	set("objects", 
	([ //sizeof() == 1
//               __DIR__"npc/jieding" : 1,
	]));


        set("outdoors", 1);

	setup();
}


