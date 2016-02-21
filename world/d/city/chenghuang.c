//Cracked by Roath
//changan city

inherit ROOM;
//#include "/d/obj/misc/jitan.h"

void create ()
{
        set ("short", "城隍庙");
        set ("long", @LONG

这里始终是香火缭绕，台上供奉着一尊威严的神像。然来
当地居民特地将保护本地区的门派掌门人的神像供奉在这
里,以祈求百姓的安居乐业。
LONG);

//  set("no_quit",1);
//  set("no_flee",1);
//  set("alternative_die",1);
        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
		"south" : __DIR__"qinglong-e3",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/keeper" : 1,
                __DIR__"npc/guan" : 1,
        ]));

//        set("outdoors", "changan");
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}



