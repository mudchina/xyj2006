// Empty.c

inherit ROOM;

void create()
{
        set("short", "empty room");
        set("long", @LONG

Empty room for special usage
  1. transition phase when special NPCs die
  2. NPCs hide temporarily
  3. NPCs transform to other NPCs with delay

LONG
        );


        set("exits", ([ /* sizeof() == 2 */
  "up" : "/d/city/center",
]));
        set("no_clean_up", 0);
        set("no_fight", 1);
        set("no_magic", 1);
        setup();
        replace_program(ROOM);
}

