// 洞内
// by lestat 2001

inherit ROOM;

void create()
{
        set("short", "洞内");
        set("long", @LONG
但听得耳边轰聋聋的响声越来越大，山崖也逐渐变得倾斜，而不再象上
面那么陡峭笔立了，终于到达谷底了。只见上面的上崖一条大瀑布如玉龙悬
空，滚滚而下，倾入了一座清澈异常的大湖之中。甚为壮观。
LONG );
        set("exits", ([
		"south" : __DIR__"yanfeng",
		"west" : __DIR__"hubian",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
