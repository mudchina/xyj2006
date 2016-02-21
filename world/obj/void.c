// Void.c

inherit ROOM;

void create()
{
        set("short", "十八层地狱");
        set("long", @LONG

血！血！ 血！ 到处都是流不尽的血！
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

