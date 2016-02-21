//created by vikee
//2000.10

inherit ROOM;
 
void create()
{
   set("short", "八卦炉　离宫");
   set("long",@LONG

这八卦炉中四处都是文武之火，坐在其中，只感到浑身燥热难当。

LONG
        );
 
   set("exits", ([
        "east" : __DIR__"bgl4",
        "north" : __DIR__"bgl6",
                "west" : __DIR__"bgl8",
                "south" : __DIR__"bgl2",
   ]));
    set("valid_startroom", 1);
   set("objects",([
      "/d/dntg/sky/npc/huobing" : 1,      
   ]));



        setup();
}

