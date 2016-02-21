// Room: some place in 西牛贺洲
// inside2.c

inherit ROOM;

void create()
{
  set ("short", "卧室");
  set ("long", @LONG

老神仙也要睡觉．在这你就尽情的睡吧．

LONG);
set("exits", ([ /* sizeof() == 4 */
"north": __DIR__"inside2",
]));
set("objects", ([
               "/d/obj/weapon/stick/bang": 1]));

        set("no_clean_up", 0);
        set("sleep_room",1);
        set("if_bed",1);

        setup();
        replace_program(ROOM);
}



