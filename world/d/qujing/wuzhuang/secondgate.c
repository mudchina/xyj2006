//Cracked by Roath
inherit ROOM;

void create ()
{
	set ("short", "二山门");
	set ("long", @LONG

二山门远看极是高大，牌楼上隐有祥云绕绕。左右石柱上刻口一
对春联，乃是“长生不老神仙府，与天同寿道人家”十四个龙飞
凤舞的大字。
LONG);

	set("exits", 
	([ //sizeof() == 4
		"southdown" : __DIR__"shaoxiang",
		"north" : __DIR__"linkway",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		//__DIR__"npc/***" : 1,
	]));


	set("outdoors", "wuzhuang");

	setup();
}
