// washing.c

inherit ROOM;

void create()
{
  set ("short", "洗衣房");
  set ("long", @LONG

地下到处流着脏水，一个老妈子正洗着一堆衣服．
LONG);
set("exits", ([ /* sizeof() == 4 */
"west" :__DIR__"houyuan",
]));
set("objects", ([ 
		__DIR__"npc/washer": 1]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}


