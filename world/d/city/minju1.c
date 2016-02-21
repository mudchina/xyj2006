//changan city

inherit ROOM;

void create ()
{
        set ("short", "民居");
        set ("long", @LONG

这是一户长安城里普普通通的民宅，小夫妇俩朴实勤劳，因此，家境
虽然说不上富裕，但也丰衣足食。屋中并没有什么好的摆设，木桌上
的玻璃瓶中插了几朵野花。
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
		"west" : __DIR__"beiyin1",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/dog" : 1,
		__DIR__"npc/girl" : 1,
		__DIR__"npc/liyu" : 1,
        ]));


//        set("outdoors", "changan");
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}



