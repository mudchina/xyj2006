//changan city

inherit ROOM;

void create ()
{
        set ("short", "朱雀大街");
        set ("long", @LONG

朱雀大街上商家众多，大大小小的店铺比邻而立，看起来是相当的豪
华富足。宽阔的石板路直通南北，向北通到皇宫的朝阳门，向南可遥
望到青青的终南山。西边一条小路灰蒙蒙的，东边通向望南街。
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
		"south" : "/d/changan/nanchengkou",
                "north" : __DIR__"zhuque-s3",
                "west" : __DIR__"beiyin5",
                "east" : "/d/eastway/wangnan5",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                "/d/penglai/npc/laitou" : 1,
        ]));


        set("outdoors", "changan");
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}

