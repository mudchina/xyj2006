inherit ROOM;                                                        

void create ()
{
  set ("short", "╬Ьоице" );   

    set("exits", ([ 
               "southeast" : __DIR__"jinguang",
                  ]));
    set("objects", ([ 
               "/d/zhuxian/npc/shuishen" : 1,
                  ]));
    setup();
}
