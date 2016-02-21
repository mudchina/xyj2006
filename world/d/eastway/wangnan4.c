inherit ROOM;

void create ()
{
        set ("short", "望南街");
        set ("long", @LONG

东城的望南街道路宽广，周围所住大多是有钱人家，路两旁多是些深
宅大院，院墙高立。路上铺着青石，路边栽着成行的柳树，柳枝随风
飘摆不定。北边是进士场，也是文人墨客聚集的地方。
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "east" : __DIR__"wangnan3",
                "southwest" : __DIR__"wangnan5",
		"north" : __DIR__"jinshi",
        ]));

        set("objects", 
        ([ //sizeof() == 1
//                __DIR__"npc/libai" : 1,
        ]));


        set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

