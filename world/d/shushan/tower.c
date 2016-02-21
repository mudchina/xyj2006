//Cracked by Roath
//【蜀山剑派】dhxy-evil 2000.7.5

inherit ROOM;                                                        
#include <ansi.h>                                                                     

void create ()                                                       
{                                                                    
  set ("short", HIG"镇妖塔"NOR);                                   
  set ("long", @LONG                                                 
 高耸入云的铁塔，听说里面装着无数妖怪，旁边有一石碑(stone)。                                           
LONG);                                                          
        set("item_desc", ([
                "stone": @TEXT
镇妖塔，内囚妖魔无数，闲人勿近！

TEXT        ]) );
                                                                     
    set("exits", ([ /* sizeof() == 1 */                              
  "enter" : __DIR__"entrance",                                                                              
  "south" : __DIR__"bamboo",
                                     
]));

set("objects",([
        __DIR__"npc/lxy" : 1,
        __DIR__"npc/linyueru" : 1,
    ]));                                                                 
     set("outdoors", "shushan");                                                                  
  setup();                                                           
}
