inherit ROOM;                                                        

void create ()
{
  set ("short", "б╬оице" );   

    set("exits", ([ 
               "northeast" : __DIR__"tianjue",
                  ]));
    set("objects", ([ 
               "/d/zhuxian/npc/huoshen" : 1,
                  ]));
    setup();
}
