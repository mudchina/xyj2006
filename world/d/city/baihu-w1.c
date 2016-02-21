//changan city

inherit ROOM;

void create ()
{
        set ("short", "白虎大街");
        set ("long", @LONG

你走在一条宽阔的石板大街上，东面就快到城中心了，可以看到钟楼
耸立于前。北面静静的是一家书局，来往多是些读书人。南面是一家
钱庄，整天看见客人进进出出，显得生意很兴隆。
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
		"south" : __DIR__"bank",
                "north" : __DIR__"bookstore",
                "west" : __DIR__"baihu-w2",
                "east" : __DIR__"center",
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


