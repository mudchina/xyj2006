//changan city

inherit ROOM;

void create ()
{
        set ("short", "青龙大街");
        set ("long", @LONG

你走在一条宽阔的石板大街上，西面就快到城中心了，可以看到钟楼
耸立于前。北面是城中的清虚观，有些道士模样的人出入。南面一座
大宅，门口有些兵士巡逻，是大将秦叔宝的府第。
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
		"north" : __DIR__"qingxuguan",
                "south" : "/d/jjf/gate",
                "west" : __DIR__"qinglong-e1",
                "east" : __DIR__"qinglong-e3",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/youxia" : 1,
        ]));


        set("outdoors", "changan");
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}

