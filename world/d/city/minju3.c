//changan city

inherit ROOM;

void create ()
{
        set ("short", "民居");
        set ("long", @LONG

这栋房子里象是很久没有人居住了，墙脚屋檐下到处都是灰。还经常
可以看到肥肥的老鼠跑来跑去。院中杂草从生，还可听到几声蛐蛐叫。
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
		"north" : __DIR__"beiyin3",
        ]));

        set("objects", 
        ([ //sizeof() == 1
		__DIR__"npc/rat" : 3,
		"/d/qujing/wudidong/npc/bianfu" : 1,
        ]));


//        set("outdoors", "changan");
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}



