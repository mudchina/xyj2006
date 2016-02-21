// Room: some place in 西牛贺洲
// inside2.c

inherit ROOM;

void create()
{
  set ("short", "练功室");
  set ("long", @LONG

室中静悄悄的，几位道长正在打座练功。
LONG);
set("exits", ([ /* sizeof() == 4 */
"west": __DIR__"inside2",
]));
set("objects", ([
                __DIR__"npc/huiliu": 1,
		__DIR__"npc/huigang": 1,

]) );
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}



