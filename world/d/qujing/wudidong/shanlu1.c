// Room: /d/qujing/wudidong/shanlu1.c

inherit ROOM;

void create()
{
	set("short", "山腹");
	set("long", @LONG

四处黑沉沉的，什么也看不清，只能摸索着前进。地面颇为潮湿，霉
气扑鼻。两边壁上都是凹凸不平的尖石，脚下也是时高时低。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"temple-houdian",
  "southwest" : __DIR__"shanlu2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
