// gate.c

inherit ROOM;

void create()
{
  set ("short", "铁铺");
  set ("long", @LONG

铁铺的主人是老李头，他打的铁器坚固耐用，名气在方圆几十里
是没的说．他这里的生意也特别的好．屋里到处是铁器，两个学
徒正帮着老李头打造农具．
LONG);
set("exits", ([ /* sizeof() == 4 */
"north" : __DIR__"road2",
]));

set("objects", ([
                __DIR__"npc/laoli": 1,
		__DIR__"npc/xuetu": 2]) );
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}


