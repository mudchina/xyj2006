// xiaolin1.c

inherit ROOM;

void create()
{
  set ("short", "小树林");
  set ("long", @LONG

林中光线暗淡，隐约看到几个人围作一团说着什么。传来一股
烤肉的味道，令你不禁咽了口唾沫。
LONG);
set("exits", ([ /* sizeof() == 4 */
"east" : __DIR__"shanlu",
"south" : __DIR__"xiaolin",
]));

set("objects", ([
                __DIR__"npc/tufei": 4,
                __DIR__"npc/guard": 1 
 ]) );

        set("outdoors", 1);
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}


