//changan city

inherit ROOM;

void create ()
{
        set ("short", "袁氏草堂");
        set ("long", @LONG

这里是袁守诚先生算卦测字的地方。提起袁守诚，长安城中无人不晓，
他乃是当朝钦天监台正先生袁天罡的叔父。小屋里整日访客络绎不绝。
堂上挂一幅对联，乃是：
            知凶定吉，开谈风雨迅
            断死言生，下笔鬼神惊
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "south" : __DIR__"baihu-w3",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                  __DIR__"npc/yuanshouchen" : 1,
		__DIR__"npc/xiushi" : 1,
        ]));


//        set("outdoors", "changan");
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}



