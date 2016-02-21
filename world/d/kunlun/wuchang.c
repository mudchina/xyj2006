inherit ROOM;

void create ()
{
        set ("short", "练武场");
        set ("long", @LONG

    这是玉虚洞前的一块平地，供本派弟子练功之用。几个仙童
正在练习剑术。

LONG);

        //set("item_desc", ([" *** " : " *** \n", ]));
        //for look something.

        set("exits", 
        ([ //sizeof() == 4
                "south" : __DIR__"lingyunge",
                "north" : __DIR__"dadian",
        ]));
        
        set("objects", 
        ([ //sizeof() == 1
               __DIR__"npc/xiaotong" : 2,
        ]));


        set("outdoors", "kunlun");

        setup();
}
