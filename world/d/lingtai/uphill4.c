// Room: some place in 西牛贺洲
// uphill4.c

inherit ROOM;

void create()
{
  set ("short", "碧萝岭");
  set ("long", @LONG

这里的地势变的平坦，一片碧绿的草坪中开着朵朵小花。往山下
望去，你吃了一惊，不知不觉中已上了这么高了。遥望远处，千
峰开戟，万仞开屏。日映岚光轻锁翠，雨收黛色冷含青。
LONG);
set("exits", ([ /* sizeof() == 4 */
"east": __DIR__"guanjin",
"northeast" : __DIR__"uphill5",
"southwest": __DIR__"uphill3",
]));
set("objects", ([ /* sizeof() == 2 */
"/d/lingtai/npc/qiaofu.c" : 1]));

        set("no_clean_up", 0);
	set("outdoors", 1);
        setup();
        replace_program(ROOM);
}


