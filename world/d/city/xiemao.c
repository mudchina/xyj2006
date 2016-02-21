//changan city

inherit ROOM;

void create ()
{
        set ("short", "鞋帽店");
        set ("long", @LONG

这里的东西都相当不错，城里的太太小姐多来这里买衣服。逢年过节来
光顾的人就更多了。屋中横放一张七尺多长的柜台，柜台后的架子上是
一匹匹的布料和成衣。
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "west" : __DIR__"zhuque-s3",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/xiaoliu" : 1,
		__DIR__"npc/eryi" : 1,

        ]));


//        set("outdoors", "changan");
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}

