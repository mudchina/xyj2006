//sgzl
inherit ROOM;

void create ()
{
	set ("short", "雪岭");
	set ("long", @LONG

茫茫的山坡上一望无际的白雪，上面落着几对浅浅的足迹，显然能
攀援到这一层的雪山弟子，轻功几然十分了得了。
LONG);


	set("exits", 
	([ //sizeof() == 4
                "down" : __DIR__"xuejie-3",
                "west" : __DIR__"no4-w1",
                "east" : __DIR__"no4-e",
"up" : __DIR__"lingjiudong",
	]));
	set("objects", 
	([
                __DIR__"npc/chongzi" : 2,
	]));


	set("outdoors", "xueshan");

	setup();
}


