// Room: /d/jjf/qilin.c

inherit ROOM;

void create()
{
	set("short", "麒麟阁");
	set("long", @LONG

太宗李世民在即位前受封秦王，手下谋臣勇将为建立李氏王朝立下了
汗马功劳。高祖为这些功臣们特起了一座彩楼，名曰「麒麟阁」。此
楼飞檐挂角，雕梁画栋，吸引了无数百姓前来观看。
LONG
	);
	set("no_fight", 1);
	set("item_desc", ([ /* sizeof() == 1 */
  "up" : "楼上人声喧哗，想是传杯送盏，酒兴正至半酣。
",
]));
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 1 */
           __DIR__"npc/qinbing" : 2,
            "/d/jjf/npc/chengyaojin": 1,
]));
	set("light_up", 1);
	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"qilin2",
  "east" : "/d/city/xuanwu-n0",
]));

	setup();
	replace_program(ROOM);
}
