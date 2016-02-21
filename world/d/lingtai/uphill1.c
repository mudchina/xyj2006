// Room: some place in 西牛贺洲
// uphill1.c

inherit ROOM;

void create()
{
  set ("short", "妙音坡");
  set ("long", @LONG

走在山间小路，两边奇花瑞草，修竹乔松。修竹乔松，万载常
青欺福地；奇花瑞草，四时不谢赛蓬瀛。在这里歇歇脚，看看
景色，闻闻花香也是很好的享受。
LONG);
set("exits", ([ /* sizeof() == 4 */
"north" : __DIR__"uphill2",
"southdown": __DIR__"hill",
]));

        set("no_clean_up", 0);
        set("outdoors", 1);
        setup();
        replace_program(ROOM);
}


