// created by wxb 12/24/1998
// room: /d/qujing/huangfeng/minju2.c

inherit ROOM;

void create ()
{
        set ("short", "民居");
        set ("long", @LONG

这里是村长的家，几件家俱是托人从长安捎来的，富丽华贵。
案上焚了一炉香，浓浓的香气扑面而至。老村长热情好客，
见你进来立该起身迎了上来。

LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 2
		"north" : __DIR__"tulu3",
                "south" : __DIR__"chufang",
        ]));

        set("objects", 
        ([ //sizeof() == 1
         __DIR__"npc/cunzhang" : 1,
         "/d/obj/misc/tables" : 1,
        ]));
      
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}
