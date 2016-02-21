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
                "east" : __DIR__"no4-wn1",
                "south" : __DIR__"no4-w2",
	]));
	
	set("objects", 
	([
                __DIR__"npc/xiezi" : 1,
	]));


	set("outdoors", "xueshan");

	setup();
}

