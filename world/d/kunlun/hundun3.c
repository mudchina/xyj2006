inherit ROOM;                                                        
                                                                     
void create ()                                                       
{                                                                    
  set ("short", "混沌中");                                   
  set ("long", @LONG                                                 
 
四周一片云雾，使你快要分不清方向，还是趁能看到

路的时候赶快走吧。
                                           
LONG);                                                          
                                                                     
    set("exits", ([ /* sizeof() == 1 */                              
  "north" : __DIR__"hundun4",                                         
  "east" : __DIR__"hundun",                                    
  "west" : __DIR__"hundun",                                       
  "south" : __DIR__"hundun",
                                     
]));                                                                 
                                                                     
  setup();                                                           
}
