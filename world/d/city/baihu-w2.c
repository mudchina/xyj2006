//changan city

inherit ROOM;

void create ()
{
        set ("short", "白虎大街");
        set ("long", @LONG

你走在一条宽阔的石板大街上，东面就快到城中心了，可以看到钟楼
耸立于前。北边是家大的酒楼，里面唏唏嚷嚷，热闹非凡。而南却是
家规模不小的寺院，往西就快要出城了。
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
		"south" : __DIR__"huashengsi",
                "north" : __DIR__"xifuhui",
                "west" : __DIR__"baihu-w3",
                "east" : __DIR__"baihu-w1",
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


