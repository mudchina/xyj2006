//Cracked by Roath
inherit ROOM;
inherit "/d/wiz/no_get";

void create ()
{
	set ("short", "睡房");
	set ("long", @LONG

睡房中整齐的摆着二三十个软榻，上面铺着玄色的被子。室中
非常的安静，偶尔从外面的竹林中传来一两声鸟叫。
LONG);

  set("no_magic",1);
	set("exits", 
	([ //sizeof() == 4
		"west" : __DIR__"westway5",
	]));
        set("sleep_room",1);
        set("if_bed",1);
	
	set("objects", 
	([ //sizeof() == 1
		//__DIR__"npc/qingfeng" : 1,
		//__DIR__"npc/mingyue" : 1,
	]));


//	set("outdoors", "wuzhuang");

	setup();
}
