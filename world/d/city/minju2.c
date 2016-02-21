//changan city

inherit ROOM;

void create ()
{
        set ("short", "民居");
        set ("long", @LONG

这户民宅从结构上看还是相当不错的，显示出这户人家先前似乎曾经
阔过。不知从哪一辈起家道开始衰落了，这座房子也随之年久失修。
现在这户人家的两个儿子更是整日里游手好闲，不务正业。
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
		"east" : __DIR__"beiyin3",
        ]));

        set("objects", 
        ([ //sizeof() == 1
		__DIR__"npc/xiaopizi" : 2,
        ]));


//        set("outdoors", "changan");
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}



