// yandong.c
// by shilling 97.2

inherit ROOM;

void create()
{
	set("short", "岩洞");
	set("long", @LONG
这里四周没有丝毫的光亮，每前进一步，都要先试探个虚实，但是却觉
得脚下平整，便似走在石板路上一般，只见道路不断地往下倾斜，越走越低。
LONG );
	set("exits", ([
		"north" : __DIR__"damen",
		"out" : __DIR__"hubian",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
