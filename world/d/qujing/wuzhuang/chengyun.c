//Cracked by Roath
inherit ROOM;

void create ()
{
	set ("short", "乘云阁");
	set ("long", @LONG

乘云阁居观中的最高处，阁上画栋雕梁，丹楹刻柱，显是下了很
大的功夫、周围朱栏曲槛，凭栏四望，远处景致俱在眼前。山下
村房楼舍，山上奇石怪松历历在目。
LONG);

	set("exits", 
	([ //sizeof() == 4
		"down": __DIR__"yanzhen",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		//__DIR__"npc/qingfeng" : 1,
		__DIR__"npc/zhenyuan" : 1,
	]));


	set("outdoors", "wuzhuang");

	setup();
}
