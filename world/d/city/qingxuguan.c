//changan city

inherit ROOM;

void create ()
{
        set ("short", "清虚观");
        set ("long", @LONG

清虚观是长安城里着名的一座道观。由于唐朝的皇帝和道教宗祖老子
同姓，因此道教被奉为唐朝的国教。但由于佛教的传入，道教的状况
已大大不如以前。道观中已没有几个人了，但观内原有的气势还没有
变。香案上供着元始天尊、太上老君和灵官道君的神像。
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "south" : __DIR__"qinglong-e2",
        ]));

  set("no_cast", 1);
        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/daozhang" : 1,
		"/d/lingtai/npc/xiao" : 2,
        ]));


//        set("outdoors", "changan");
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}

