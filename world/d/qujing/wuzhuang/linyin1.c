//Cracked by Roath
inherit ROOM;

void create ()
{
        set ("short", "林荫小道");
        set ("long", @LONG

这里树高影长，果熟送香。虽然只是短短的一条林荫道，行来亦
是让人清心脱俗。而东面树丛中水光掩映，想来是一片池塘。
LONG);

        set("exits", 
        ([ //sizeof() == 4
                "southeast" : __DIR__"shanlu2",
                "north" : __DIR__"linyin2",
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

