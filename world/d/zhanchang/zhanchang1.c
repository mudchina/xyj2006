inherit WARPLACE;

void create()
{
	set("short", "战场");
	set("long", @LONG
门派战斗的场地。
LONG
	);
	
	set("exits",([
	"east" : __DIR__"zhanchang/exit",
]));

	setup();
	
}
