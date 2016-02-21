//Cracked by Roath
//huludi.c

inherit ROOM;

void create ()
{
	set ("short", "葫芦地");
	set ("long", @LONG

五庄观做事的多，吃饭的也不少，所以观内雇了附近的一些农家
来种蔬菜瓜果。这里是葫芦地。
LONG);

	set("exits", 
	([ //sizeof() == 4
		"northeast" : __DIR__"xiguadi",
		"south" : __DIR__"luobodi",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		"/d/obj/food/hulu" : 2,
	]));

	//create_door("south", "梨花门", "north", DOOR_CLOSED);
	set("outdoors", "wuzhuang");

	setup();
}
