// under2.c

inherit ROOM;

void create ()
{
  set ("short", "海底莽林");
  set ("long", @LONG

这里水色变的浑浊起来，周围已看不大清楚了。偶有暗流袭来，卷
起阵阵的泥流。四处长着些高高的海草，密密麻麻把头上遮的一丝
光芒也没有了。
LONG);

  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/beast3" : 1,
]));
  set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"maze"+sprintf("%d",random(10)),
  "north" : __DIR__"maze"+sprintf("%d",random(10)),
  "south" : __DIR__"maze"+sprintf("%d",random(10)),
  "west" : __DIR__"maze"+sprintf("%d",random(10)),
]));
//      
        set("water", 1);
//  
        setup();
}

