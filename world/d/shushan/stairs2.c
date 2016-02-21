//Cracked by Roath
//【蜀山剑派】dhxy-evil 2000.7.5
inherit ROOM;                                                        
                                                                     
void create ()                                                       
{                                                                    
  set ("short", "第二层迷宫");                                   
  set ("long", @LONG                                                 
四周是石壁的迷宫，只见上方有个洞，应该是通向第三层的。                                           
LONG);                                                          
                                                                     
    set("exits", ([ /* sizeof() == 1 */                              
  "up" : __DIR__"three1",                                                                             
  "north" : __DIR__"two7",                                       
                                     
]));                                                                 
    set("objects",([
        __DIR__"npc/fool" : 1,
        __DIR__"obj/fbook" : 1,
    ]));                                                                      
  setup();                                                           
}

int valid_leave(object me, string dir)
{

   if (dir == "up" ) {
        if (objectp(present("fool", environment(me))))
   return notify_fail("你没看见有鬼挡住路吗！”\n");
        }   
        return ::valid_leave(me, dir);
}
