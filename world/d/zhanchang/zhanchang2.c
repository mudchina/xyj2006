
inherit WARPLACE;

void create()
{
	set("short", "战场");
	set("long", @LONG
门派战斗的场地。
LONG
	);

	set("exits", ([
	"west" : __DIR__"zhanchang/entry",
	
]));

	setup();
	
}
