//changan city

inherit ROOM;

void create ()
{
        set ("short", "民居");
        set ("long", @LONG

这户人家在长安城里也算比较富裕的了。男主人常年经商在外，妻子
在家主持家务。如同长安城大多数人家一样，屋里供着南海观音和关
王爷的神像。
LONG); 

        //set("item_desc", ([" *** " : " *** ", ])); 

        set("exits", 
        ([ //sizeof() == 4
		"north" : __DIR__"beiyin5",
        ]));

        set("objects", 
        ([ //sizeof() == 1
		__DIR__"npc/woman" : 1,
		__DIR__"npc/boy" : 1,
		"/d/obj/weapon/blade/caidao" : 1,
        ]));


//        set("outdoors", "changan");
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}



