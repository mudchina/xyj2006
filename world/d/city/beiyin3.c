//changan city

inherit ROOM;

void create ()
{
        set ("short", "背阴巷");
        set ("long", @LONG

背阴巷位于长安城之西南，住户大多是些贫苦人家。由于官府很少管
这里，所以治安并不十分好。周围民居破落，路边杂草丛生，到处是
沉闷的灰色，不见一丝生机。来往的人大多是衣衫褴褛，满面愁色。
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
		"north" : __DIR__"beiyin2",
                "east" : __DIR__"beiyin4",
		"west" : __DIR__"minju2",
		"south" : __DIR__"minju3",
        ]));

        set("objects", 
        ([ //sizeof() == 1
//                __DIR__"npc/libai" : 1,
        ]));


        set("outdoors", "changan");
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}


