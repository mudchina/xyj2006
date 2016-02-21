//changan city

inherit ROOM;

void create ()
{
        set ("short", "喜福会");
        set ("long", @LONG

这里正在举行一个喜宴，堂内张灯结彩，台上高点红烛，一些歌女舞
娘正随乐而舞，四五个小伙计麻利的上菜送酒。周围坐满了前来祝贺
的客人，热闹非凡。
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
		"south" : __DIR__"baihu-w2",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/boss" : 1,
        ]));


//        set("outdoors", "changan");
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}


