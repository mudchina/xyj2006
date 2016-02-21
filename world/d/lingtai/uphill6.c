// Room: some place in 西牛贺洲
// uphill6.c

inherit ROOM;

void create()
{
  set ("short", "青石阶");
  set ("long", @LONG

石阶向前延续，隐隐约约已可看见山门，门旁两株松树毅然而立。
你也不由高兴起来。随着脚下踏踏，心儿也踏踏的跳，真想一步跨
到门口去看个究竟。
LONG);
set("exits", ([ /* sizeof() == 4 */
"northup" : __DIR__"gate",
"southdown": __DIR__"uphill5",
]));
	set("objects", 
	([ //sizeof() == 1
		"/d/xueshan/npc/qingshi-laomo" : 1,
	]));

        set("no_clean_up", 0);
	set("outdoors", 1);
        setup();
        replace_program(ROOM);
}


