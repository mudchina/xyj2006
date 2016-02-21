// Room: /d/qujing/wudidong/temple-gate.c

inherit ROOM;

void create()
{
	set("short", "华严寺");
	set("long", @LONG

转眼你已来至山顶，云雾缭绕，如似蓬莱仙境。 眼前，一座
寺院拔地而起，寺门上一块横匾，上书「华严寺」。但不知
为何，寺门紧闭，尘灰遍地，似乎很久没有人出落了。 门前
一道小路，继续往西而去。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"road1",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
