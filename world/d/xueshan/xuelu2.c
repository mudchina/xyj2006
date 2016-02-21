//sgzl
inherit ROOM;

void create ()
{
	set ("short", "雪路");
	set ("long", @LONG

前面的路已完全弥漫在满天飞雪之中，雪下得一发大了，
足底溜滑，道路更是难於辨认，若是踏一个空，势必掉
在万仞深谷中跌得粉身碎骨。
LONG);


	set("exits", 
	([ //sizeof() == 4
		"southdown" : __DIR__"xuelu1",
		"northup" : __DIR__"xuelu",
	]));
	
	set("objects", 
	([ //sizeof() == 1
	]));


	set("outdoors", "xueshan");

	setup();
}



