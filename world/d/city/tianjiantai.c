//changan city

inherit ROOM;

void create ()
{
        set ("short", "天监台");
        set ("long", @LONG

这里便是长安城钦天监台，朝廷每年的祭天仪式都在这里举行。中央
广场上画着八卦图形，周围还摆这一些施法时用的器具．天监台的总
管是正先生袁天罡，总可在这里看到他的身影。
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "east" : __DIR__"xuanwu-n1",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/yuantiangang" : 1,
        ]));


        set("outdoors", "changan");
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}

