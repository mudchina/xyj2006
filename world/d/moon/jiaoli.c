//Cracked by Roath
// Room: jiaoli.c
// AceP

inherit ROOM;

int do_quit();

void create()
{
	set("short", "花轿里面");
	set("long", @LONG
这是花轿里面，是新娘子出嫁的时候坐的，恭喜恭喜！祝您新婚快乐！^_^
LONG
	);

	setup();
}

void init()
{
	add_action("do_quit","quit");
}

int do_quit()
{
	tell_object(this_player(), "什么？！难道你敢逃婚不成？！");
	return 1;
}
