//Cracked by Roath
//juyuan.c
#include <room.h>
inherit ROOM;

void create ()
{
	set ("short", "菊园");
	set ("long", @LONG

梨花门外却不是梨园。这里各种各色的菊花争奇斗艳。你不由得
放轻了脚步，唯恐一个不小心，惊落了娇艳欲滴的花瓣。东北一
亭俏立，隐约可见“牡丹亭”几字。
LONG);

	set("exits", 
	([ //sizeof() == 4
		"northeast" : __DIR__"mudanting",
		"northwest" : __DIR__"shuoyaopu",
		"south" : __DIR__"houyuan",
		//"west" : __DIR__"westway6",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		//__DIR__"npc/qingfeng" : 1,
		//__DIR__"npc/mingyue" : 1,
	]));

	create_door("south", "梨花门", "north", DOOR_CLOSED);
	set("outdoors", "wuzhuang");

	setup();
}
