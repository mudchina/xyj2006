//Cracked by Roath
//【蜀山剑派】dhxy-evil 2000.7.5
#include <ansi.h>
inherit ROOM;                                                        
                                                                     
void create ()                                                       
{                                                                    
  set ("short", HIM"镇塔柱"NOR);                                   
  set ("long", @LONG                                                 
你在镇妖塔的中心，你真的想把它这根柱子给打碎(break)。                                           
LONG);                                                          
                                                                     
    set("exits", ([ /* sizeof() == 1 */                              
        "south" : __DIR__"hole6",                                      
]));                                                                                                                          
    set("objects",([
        __DIR__"npc/dragon7" : 1,
    ]));    
  setup();                                                           
}

void init()
{
        add_action("do_break", "break");
}

int do_break(string arg)
{
        object room, ob;
        object me = this_player();

        if (me->query("nyj/shushan")=="done")
                return notify_fail("你救过灵儿，还来这里干嘛？\n");
        if (query("exits/out"))
                return notify_fail("镇塔巨柱已经破了。\n");
        if (objectp(present("dragon", environment(me))))
        return notify_fail("你还是先把龙给干了吧？\n");
        if (!arg || (arg != "hole"))
                return notify_fail("你要打碎什么？\n");

        if(!( room = find_object(__DIR__"tower")) )
                room = load_object(__DIR__"tower");
        if(objectp(room))
        {
                room->delete("exits");
                room->set("long","镇妖塔已经倒了，要离开只能飞。(fly)\n");                                      
                set("exits/out", __DIR__"tower");
                message_vision("$N用尽全力，把镇塔柱打碎！\n", this_player());
                write(CYN"赵灵儿道：“快出去，逍遥哥哥在等我们呢！”\n");
                write("鬼王突然出现在一阵烟雾之中。\n");
                write("鬼王道：“了不起，这里几百年来从没有生物能成功逃离，我看你还是第一个！”\n");
                write("鬼王突然消失在一阵烟雾之中。\n"NOR);                              
        }

        return 1;
}