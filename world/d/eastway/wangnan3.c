inherit ROOM;

void create ()
{
        set ("short", "望南街");
        set ("long", @LONG

东城的望南街道路宽广，周围所住大多是有钱人家，路两旁多是些深
宅大院，院墙高立。路上铺着青石，路边栽着成行的柳树，柳枝随风
飘摆不定。街上行人不多，东南一条小路不知通向何方。
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "north" : __DIR__"wangnan2",
                "west" : __DIR__"wangnan4",
		"southeast" : __DIR__"guandao2",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                "/d/obj/book/misc" : 1,
        ]));


        set("outdoors", "changan");
        setup();
        replace_program(ROOM);
}

