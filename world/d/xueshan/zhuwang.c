
inherit ROOM;

void create ()
{
	set ("short", "蜘蛛网内");
	set ("long", @LONG

密密麻麻的蛛网遮住的你的视线，你只能看见对面一只
五彩蜘蛛抡着巨大的八只爪子向你爬来。
LONG);

	set("exits", 
	([ //sizeof() == 4
		"out" : __DIR__"no4-wn1",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		__DIR__"npc/zhizhu" : 1,
	]));

	setup();
}

int valid_leave(object me, string dir)
{
   if(present("wucai zhizhu", environment(me) ))
     return notify_fail("五彩蜘蛛庞大的身躯挡住了去路。\n");
   return ::valid_leave(me,dir);
}


