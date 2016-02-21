// Room: some place in 西牛贺洲
// houyuan.c

inherit ROOM;

void create()
{
  set ("short", "后院");
  set ("long", @LONG

后院之中空空荡荡，只有一个小道士在扫着院子。北方一个古香
古色的阁楼，隐约看到门上写着『藏经阁』三个字。东边和南边
是一些师兄弟的住处。
LONG);
set("exits", ([ /* sizeof() == 4 */
"southwest": __DIR__"inside1",
"south": __DIR__"inside6",
"north": __DIR__"jingge",
"east": __DIR__"inside4",
]));
set("objects", ([
                __DIR__"npc/xiaodao": 1 ]) );
        set("no_clean_up", 0);
	set("outdoors", 1);
        setup();
        replace_program(ROOM);
}

