//Cracked by Roath
//【蜀山剑派】dhxy-evil 2000.7.5
inherit ROOM;                                                        
                                                                     
void create ()                                                       
{                                                                    
  set ("short", "巨柱");                                   
  set ("long", @LONG                                                 
一根巨柱矗立在你的面前，你想回头，但你惊讶地发现，你并没有退路。                                           
LONG);                                                          
                                                                     
    set("exits", ([ /* sizeof() == 1 */                              
  "north" : __DIR__"saveling",                                      
]));                                                                                                                          
    set("objects",([
        __DIR__"npc/mingwang" : 1,
    ]));   
  setup();                                                           
}
int valid_leave(object me, string dir)
{

   if (dir == "north" ) {
   		if (me->query_temp("save_linger")==1)
	   		return ::valid_leave(me, dir);


		if (objectp(present("zhenyu mingwang", environment(me))))
   return notify_fail("镇狱明王拦住路不让你过！”\n");
        }   
        
		return ::valid_leave(me, dir);
}
