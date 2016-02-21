// Room: some place in 西牛贺洲
// uphill5.c

inherit ROOM;

void create()
{
  set ("short", "青石阶");
  set ("long", @LONG

一条长长的石阶连向山顶的，石面光滑，似乎常年有人走过。两边
松树错落有致，象是有人保养，却看不到一个人影。
LONG);
set("exits", ([ /* sizeof() == 4 */
"northup" : __DIR__"uphill6",
"southwest": __DIR__"uphill4",
]));

        set("no_clean_up", 0);
	set("outdoors", 1);
        setup();
        replace_program(ROOM);
}


