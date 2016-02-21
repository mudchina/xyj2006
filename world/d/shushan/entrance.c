//Cracked by Roath
//【蜀山剑派】dhxy-evil 2000.7.5
inherit ROOM;                                                        
#include <ansi.h>                                                                     
void create ()                                                       
{                                                                    
  set ("short", HIG"镇妖塔入口"NOR);                                   
  set ("long", @LONG                                                 
镇妖塔入口，正面有一扇石门(door)。                                           
LONG);                                                          
        set("item_desc", ([
                "door": @TEXT
坚硬无比的石门，恐怕要用真气(break)！
TEXT        ]) );
                                                                     
    set("exits", ([ /* sizeof() == 1 */                              
  "out" : __DIR__"bamboo4",      
]));                            
set("objects",([__DIR__"obj/jar":1,]));                                     
                                                                     
  setup();                                                           
}                                  

void init()
{
        add_action("do_break", "break");
}

int do_break(string arg)
{
        object room;
        object me = this_player();

        if (objectp(present("gui wang", environment(me))) ||objectp(present("jar", environment(me)))) 
                return notify_fail("凭你自己的能力恐怕打不开。\n");

        if (query("exits/north"))
                return notify_fail("大门已经是破了。\n");

        if (!arg || (arg != "men" && arg != "door" && arg != "north"))
                return notify_fail("你要打碎什么？\n");

        if(!( room = find_object(__DIR__"one1")) )
                room = load_object(__DIR__"one1");
        if(objectp(room))
        {
                set("exits/north", __DIR__"one1");
                write(CYN"鬼王突然出现在一阵烟雾之中。\n");
                write("鬼王说道：“这门我来打碎吧。”\n");
                write("鬼王一拳把石门打得粉碎！\n");
                write("鬼王突然消失在一阵烟雾之中。\n"NOR);
                room->set("exits/south", __FILE__);
                
        }

        return 1;
}