// gate.c

inherit ROOM;

void create()
{
  set ("short", "稻田");
  set ("long", @LONG

稻田里村民们正在耕种着．一片一片的农田连结成网，小沟小渠
密布其中．
LONG);
set("exits", ([ /* sizeof() == 4 */
"south" : __DIR__"road4",
]));
set("objects", ([
                __DIR__"npc/farmer": 1,
		__DIR__"npc/bull": 1 ]) );


        set("outdoors", 1);
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}


