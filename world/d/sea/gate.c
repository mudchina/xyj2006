// gate.c

inherit ROOM;

void create ()
{
  set ("short", "龙宫大门");
  set ("long", @LONG

嵌在宫殿各处的珍宝发出的光芒耀得你连眼睛都睁不开了。依稀看　　　
到宫门上方挂这一幅方匾，上有＂东海龙宫＂四个大字。几名虾兵　　　
蟹将分列两旁，警惕的盯着来往的人。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"under4",
  "east" : __DIR__"inside1",
]));
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/soldier1" : 2,
  __DIR__"npc/soldier2" : 2,
]));
//      
        set("water", 1);
//  
        setup();
}

