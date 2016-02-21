//Cracked by Roath
inherit ROOM;

void create ()
{
        set ("short", "山路");
        set ("long", @LONG

山路蜿转不定，缓势延往山上。遥望山颠隐见祥云片片，东边闻
水声阵阵，乃是一个深涧。前方树林外见一道观，想来定是好人
家。
LONG);

        set("exits", 
        ([ //sizeof() == 4
                "northwest" : __DIR__"linyin1",
                "southdown" : __DIR__"shanlu1",
                //"west" : __DIR__"binggu",
//                "east" : __DIR__"pool",
                //"up" : __DIR__"***",
                //"down" : __DIR__"***",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                //__DIR__"npc/***" : 1,
        ]));


        set("outdoors", "wuzhuang");

        setup();
}

