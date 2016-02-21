//Cracked by Roath
//【蜀山剑派】dhxy-evil 2000.7.5
inherit ROOM;                                                        
                                                                     
void create ()                                                       
{                                                                    
  set ("short", "第一层迷宫");                                   
  set ("long", @LONG                                                 
四周是石壁的迷宫，只见上方有个洞，应该是通向第二层的。                                           
LONG);                                                          
                                                                     
    set("exits", ([ /* sizeof() == 1 */                              
  "up" : __DIR__"two1",                                                                             
  "west" : __DIR__"one7",                                       
                                     
]));                                                                 
    set("objects",([
        __DIR__"npc/yuanhun" : 1,
    ]));                                                                           
  setup();                                                           
}

int valid_leave(object me, string dir)
{

   if (dir == "up" ) {
        if (objectp(present("yuan hun", environment(me))))
   return notify_fail("冤魂拦住路不让你过！”\n");
        }   
        return ::valid_leave(me, dir);
}
                        