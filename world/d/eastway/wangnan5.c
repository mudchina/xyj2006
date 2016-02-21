inherit ROOM;

void create ()
{
        set ("short", "望南街");
        set ("long", @LONG

东城的望南街道路宽广，周围所住大多是有钱人家，路两旁多是些深
宅大院，院墙高立。路上铺着青石，路边栽着成行的柳树，柳枝随风
飘摆不定。西边通向朱雀大街，东南有一座大的寺院，前去进香拜佛
的人很多。
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "west" : "/d/city/zhuque-s4",
		"south": __DIR__"petshop",
                "northeast" : __DIR__"wangnan4",
		"southeast" : __DIR__"guandao1",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/youke" : 2,
        ]));


        set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

