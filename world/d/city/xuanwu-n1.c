//Cracked by Roath
//changan city

inherit ROOM;

void create ()
{
        set ("short", "玄武大街");
        set ("long", @LONG

这里的路相当的宽，能容好几匹马车并行，长长的道路通向北方。远
远的能看到皇宫的朝阳门。西面是天监台，东边是国子监。
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
		"north" : "/d/huanggong/chaoyangmen",
                "west" : __DIR__"tianjiantai",
                "east" : __DIR__"guozijian",
                "south" : __DIR__"xuanwu-n0",
        ]));

        set("objects", 
        ([ //sizeof() == 1
//	   __DIR__"npc/japan":2,
//	   __DIR__"npc/japan2":2,
//                __DIR__"npc/libai" : 1,
        ]));


        set("outdoors", "changan");
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}

