//changan city

inherit ROOM;

void create ()
{
        set ("short", "背阴巷");
        set ("long", @LONG

背阴巷位于长安城之西南，住户大多是些贫苦人家。由于官府很少管
这里，所以治安并不十分好。周围民居破落，路边杂草丛生，到处是
沉闷的灰色，不见一丝生机。来往的人大多是衣衫褴褛，满面愁色。
北边有家小酒馆，东面是家粮店。
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
		"north" : __DIR__"jiuguan",
		"west" : __DIR__"beiyin3",
                "southeast" : __DIR__"beiyin5",
		"east" : __DIR__"liangdian",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/liumang" : 1,
        ]));


        set("outdoors", "changan");
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}


