// Room: /u/rainy/sea/xizhen.c
inherit ROOM;

void create ()
{
  set ("short", "吸真台");
  set ("long", @LONG

这里是龙宫中的一个露台，一笼轻纱遮住了后面宫室内的珠光宝器。　　
露台呈长形，周围摆设似乎有什么玄机，却一时看不出些门道。听　　　
说在这里修练能使人很容易脱污去诟而超凡入定。
LONG);
  set("dragonforce_practice",1);
  set("exits", ([ /* sizeof() == 1 */
  "northeast" : __DIR__"qingxin",
]));
//      
        set("water", 1);
//  
  setup();
}
