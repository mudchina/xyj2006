// boy1.c

inherit ROOM;

void create()
{
  set ("short", "沁玉殿");
  set ("long", @LONG

这里是龙太子住的宫殿。屋里摆设简单，仅有一桌四椅。太子平
时也不在这里，柱上的明珠将屋中照得一片通明。
LONG);
set("exits", ([ /* sizeof() == 4 */
"southwest" : __DIR__"inside1",
"northeast" : __DIR__"boy2",
]));
set("objects", ([
                __DIR__"npc/haima": 1]) );
        set("no_clean_up", 0);
//
	set("water", 1);
//
        setup();
}

