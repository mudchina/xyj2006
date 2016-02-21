// Room: /d/jjf/qilin2.c

inherit ROOM;

void create()
{
	set("short", "麒麟阁二楼");
	set("long", @LONG
二楼比起一楼来，只有更加豪华气派。墙上绘着几幅沙场景象，
一幅是秦琼走马取关，一幅是程咬金斧劈隋将。席间一位黑脸将军正
在开怀畅饮。窗外，无数百姓聚集在街对面一座彩楼前指指点点。
LONG
	);
	set("light_up", 1);
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/yuchigong" : 1,
]));
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"qilin",
]));

	setup();
	replace_program(ROOM);
}
