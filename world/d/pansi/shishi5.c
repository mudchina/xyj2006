// 紫云轩 紫霞仙子白天出现的地点
// by lestat

inherit ROOM;

void create()
{
	set("short", "紫云轩");
	set("long", @LONG
这里是紫霞仙子的卧房，每当夜幕降临的时候，紫霞仙子就不知去向了。
LONG );
	set("exits", ([
		"up" : __DIR__"shishi4",
	]));
	set("objects",([
		"/d/pansi/obj/yinsuo.c":1, 
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
