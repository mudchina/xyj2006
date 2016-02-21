//changan city

inherit ROOM;

void create ()
{
        set ("short", "化生寺");
        set ("long", @LONG

化生寺是长安城里规模最大的一家丛林了。整日里香烟袅绕，颂经声
不绝于耳。来这里上香还愿的善男信女也特别多，若到了皇道吉日，
更是人山人海。
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
		"south" : __DIR__"baodian",
                "north" : __DIR__"baihu-w2",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/sengren1" : 1,
		__DIR__"npc/sengren" : 2,
        ]));


        set("outdoors", "changan");
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}


