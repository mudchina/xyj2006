//Cracked by Roath
//【蜀山剑派】dhxy-evil 2000.7.5
inherit ROOM;                                                        
                                                                     
void create ()                                                       
{                                                                    
  set ("short", "竹林");                                   
  set ("long", @LONG                                                 
 四周长满了竹子，绿影婆裟，宛如鬼影重重，你不禁感到暗暗心惊，脚下
 也不由的加快了几分。                                           
LONG);                                                          
                                                                     
    set("exits", ([ /* sizeof() == 1 */                              
  "north" : __DIR__"bamboo",                                         
  "east" : __DIR__"bamboo",                                    
  "west" : __DIR__"bamboo3",                                       
  "south" : __DIR__"bamboo",
                                     
]));                                                                 
                                                                     
  setup();                                                           
}