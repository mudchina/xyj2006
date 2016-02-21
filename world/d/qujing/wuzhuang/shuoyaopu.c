//Cracked by Roath
//shuoyaopu.c

inherit ROOM;

void create ()
{
	set ("short", "芍药圃");
	set ("long", @LONG

圃浅花盛，宛如在地上铺开了一张火红的地毯。几位提着花蓝的
少女在此打闹嬉戏，清风拂过，袖带飘香，你不由得醉醉地吸了
一口气。
LONG);

	set("exits", 
	([ //sizeof() == 4
		"southeast" : __DIR__"juyuan",
		"north" : __DIR__"southpool",
		//"south" : __DIR__"houyuan",
		//"west" : __DIR__"westway6",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		__DIR__"npc/hexiangu" : 1,
		__DIR__"npc/girl" : 3,
	]));

	//create_door("south", "梨花门", "north", DOOR_CLOSED);
	set("outdoors", "wuzhuang");

	setup();
}
