//changan city

inherit ROOM;

void create ()
{
        set ("short", "兵器铺");
        set ("long", @LONG

刚一进门就看到兵器架上摆着各种兵器，从上百近重的大刀到轻如芥
子的飞磺石，是应有尽有。女老板是老英雄萧振远的小女儿，也是振
远镖局二老板，巾帼不让须眉。
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "north" : __DIR__"qinglong-e1",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/xiaoxiao" : 1,
        ]));


//        set("outdoors", "changan");
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}

