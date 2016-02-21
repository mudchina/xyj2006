// gate.c

inherit ROOM;

void create()
{
  set ("short", "小酒馆");
  set ("long", @LONG

镇子里就这么一家小酒馆，累了一天的生意人都会来喝几盅．酒店
里的花雕可都是正经从长安运来的，那个醇味没的说．再配上几粒
花生米，神仙也不过如此．
LONG);
set("exits", ([ /* sizeof() == 4 */
"north" : __DIR__"road1",
]));
set("objects", ([
                __DIR__"npc/wang": 1, 
		__DIR__"npc/jiuke": 1]) );

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}


