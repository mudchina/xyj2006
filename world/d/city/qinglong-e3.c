//changan city

inherit ROOM;

void create ()
{
        set ("short", "青龙大街");
        set ("long", @LONG

你走在一条宽阔的石板大街上，东边就快要出了城门，远远看到一些
兵卒来回巡逻。西边直通到城中心。北边是城内一座庙宇，香烟缭绕
，善男信女们进进出出，颇为喧闹。
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
		"south" : "/d/eastway/wangnan1",
                "north" : __DIR__"chenghuang",
                "west" : __DIR__"qinglong-e2",
                "east" : __DIR__"dongmen",
        ]));

        set("objects", 
        ([ //sizeof() == 1
//                __DIR__"npc/youxia" : 1,
        ]));


        set("outdoors", "changan");
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}

