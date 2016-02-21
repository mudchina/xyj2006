//Cracked by Roath
//luobodi.c

inherit ROOM;

void create ()
{
	set ("short", "萝卜地");
	set ("long", @LONG

五庄观做事的多，吃饭的也不少，所以观内雇了附近的一些农家
来种蔬菜瓜果。这里是萝卜地。
LONG);

	set("exits", 
	([ //sizeof() == 4
		"north" : __DIR__"huludi",
		"southeast" : __DIR__"huangguadi",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		"/d/obj/food/carrot" : 3,
	]));

	//create_door("south", "梨花门", "north", DOOR_CLOSED);
	set("outdoors", "wuzhuang");

	setup();
}
