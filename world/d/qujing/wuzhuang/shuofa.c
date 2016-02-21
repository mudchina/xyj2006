//Cracked by Roath
inherit ROOM;

void create ()
{
	set ("short", "说法堂");
	set ("long", @LONG

说法堂乃是镇元大仙为了门下弟子说法论道而设。比讲经堂略大。
中有一四方台，台上两把黑漆椅相对而立，台下软垫环绕。四面
墙上挂有些山水字画，乃是经之妙义，法门玄机。
LONG);

	set("exits", 
	([ //sizeof() == 4
		"south" : __DIR__"epiandian",
		"westup": __DIR__"yanzhen",
	]));
	
	set("objects", 
	([ //sizeof() == 1
//  "/d/obj/misc/baguafu":1,
// by canoe ，改由daxian发放
		//__DIR__"npc/qingfeng" : 1,
		//__DIR__"npc/mingyue" : 1,
	]));


//	set("outdoors", "wuzhuang");

	setup();
}
