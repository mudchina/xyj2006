//changan city

inherit ROOM;

void create ()
{
        set ("short", "国子监大院");
        set ("long", @LONG

国子监是国家培养高级人才的地方。唐朝的学风很浓，在这里不时可
以看到三三两两的学生模样的人大声争辩着什么问题，还有一些老先
生门蹙着眉头匆匆走过，象是在思考着什么问题。
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "west" : __DIR__"xuanwu-n1",
                "east" : __DIR__"guozi",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/xiucai1" : 1,
		__DIR__"npc/xiucai2" : 1,
]));


        set("outdoors", "changan");
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}

