// tongmen.c
// by lestat

inherit ROOM;

void create()
{
	set("short", "白骨洞大门");
	set("long", @LONG
这是一个月形的铜门，门旁的壁上凿着“白骨洞”三个大字。
LONG );
	set("exits", ([
		"south" : __DIR__"shiji3",
		"west" : __DIR__"fangjian3",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
