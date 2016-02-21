inherit ROOM;

void create ()
{
        set ("short", "望南街");
        set ("long", @LONG

东城的望南街道路宽广，周围所住大多是有钱人家，路两旁多是些深
宅大院，院墙高立。路上铺着青石，路边栽着成行的柳树，柳枝随风
飘摆不定。东边有座草庐，看起来相当的风雅，西边是进士场。
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "northeast" : __DIR__"wangnan1",
                "south" : __DIR__"wangnan3",
		"west": __DIR__"jinshi",
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

