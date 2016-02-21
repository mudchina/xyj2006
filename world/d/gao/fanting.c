// fanting.c

inherit ROOM;

void create()
{
  set ("short", "饭厅");
  set ("long", @LONG

饭厅中放了一张八仙桌，桌上杯碟狼籍．一伙客人刚吃过走了．小
丫环正打扫着剩汤剩饭．说是剩汤剩饭，其实好些还没碰过．
LONG);
set("exits", ([ /* sizeof() == 4 */
"west" : __DIR__"zhting",
]));
set("objects", ([
                __DIR__"npc/yahuan": 1,
]) );

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}


