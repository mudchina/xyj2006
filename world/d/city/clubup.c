//changan city

inherit ROOM;

void create ()
{
        set ("short", "长安二楼");
        set ("long", @LONG

乐坊楼上显得格外热闹，走廊里人来人往，几间屋子里人声嘈杂，牌
签骨骰钱币落盘的声音不绝。看样子，客人们赌得正欢呢。
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "up" : __DIR__"club3",
"west" : __DIR__"duchang1",
"east" : __DIR__"duchang2",
"north" : __DIR__"duchang3",
"south" : __DIR__"duchang4",
    		"down" : __DIR__"club",
        ]));

        set("objects", 
        ([ //sizeof() == 1
//                __DIR__"npc/libai" : 1,
//                "/d/obj/misc/tables" : 3,
        ]));


//        set("outdoors", "changan");
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}

