//Cracked by Roath
//【蜀山剑派】dhxy-evil 2000.7.5
inherit ROOM;                                                        
                                                                     
void create ()                                                       
{                                                                    
  set ("short", "第一层迷宫");                                   
  set ("long", @LONG                                                 
四周是石壁的迷宫，一股浓浓的妖气祢漫在空气里。                                           
LONG);                                                          
                                                                     
    set("exits", ([ /* sizeof() == 1 */                              
  "north" : __DIR__"one4",                                         
  "east" : __DIR__"stairs1",                                    
  "west" : __DIR__"one1",                                       
  "south" : __DIR__"one3",
                                     
]));
    set("objects",([
        __DIR__"npc/yao1" : 1,
        __DIR__"npc/yao2" : 1,
    ]));                                                                  
                                                                     
  setup();                                                           
}