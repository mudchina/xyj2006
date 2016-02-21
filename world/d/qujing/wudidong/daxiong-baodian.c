// Room: /d/qujing/wudidong/daxiong-baodian.c

inherit ROOM;

void create()
{
	set("short", "大雄宝殿");
	set("long", @LONG

八百罗汉，四大天王，如来，观音，应有尽有，很有点杭州灵隐的
风味。也许因为最近出了妖，香火并不是很丰盛。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"temple",
]));
	set("no_clean_up", 0);
	set("outdoors", 0);

	setup();
	replace_program(ROOM);
}
