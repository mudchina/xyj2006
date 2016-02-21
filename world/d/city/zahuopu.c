//changan city

inherit ROOM;

void create ()
{
        set ("short", "吉祥杂货铺");
        set ("long", @LONG

不知为什么西城虽大，却只有这一间杂货铺。所以每天人来人往，也
挺热闹。这里无论是油盐酱醋，还是大米白面，样样齐全。屋里打扫
的也十分干净，魏老板在和几位客人说说笑笑。
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
		"east" : __DIR__"beiyin5",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/laotou" : 1,
		__DIR__"npc/laowei" : 1,
		"/d/xueshan/npc/xunshi-out": 1,
        ]));


//        set("outdoors", "changan");
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}


