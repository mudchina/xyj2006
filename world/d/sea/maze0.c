// under2.c

inherit ROOM;

void create ()
{
  set ("short", "海底");
  set ("long", @LONG

这里水色变的浑浊起来，周围已看不大清楚了。偶有暗流袭来，卷
起阵阵的泥流。南部一片黑色，似乎把水也染黑了。
LONG);

  set("objects", ([ /* sizeof() == 2 */
//  __DIR__"npc/kid2" : 2,
]));
  set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"under3",
  "south" : __DIR__"maze1",
]));
//      
        set("water", 1);
//  
        setup();
}

void init()
{       
        object me=this_player();

                remove_call_out("greeting");
                call_out("greeting",5, me);
        
}

void greeting(object me)
{
        if( !me || environment(me) != this_object() ) return;

	message_vision("突然一阵暗流涌来，把$N冲到了莽林深处！\n", me);
	me->move("/d/sea/maze5");
	return;
}
