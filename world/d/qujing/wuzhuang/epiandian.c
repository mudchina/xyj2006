//Cracked by Roath
#include <room.h>

inherit ROOM;

void create ()
{
	set ("short", "东偏殿");
	set ("long", @LONG

东偏殿主要是待客奉茶之用。殿内摆着几对檀木椅。木壁之上挂
了几幅字画。中有一幅大书：“清虚人事少，寂静道心生”，写
得是灵妙非常，落款袁天罡。
LONG);

	set("exits", 
	([ //sizeof() == 4
		"east" : __DIR__"eastway2",
		"west" : __DIR__"zhengdian",
		"north" : __DIR__"shuofa",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		//__DIR__"npc/qingfeng" : 1,
		__DIR__"npc/mingyue" : 1,
	]));

create_door("east", "雕花木门", "west", DOOR_CLOSED);
	//set("outdoors", "wuzhuang");

	setup();
}
