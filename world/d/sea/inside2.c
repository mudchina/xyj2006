// inside2.c

inherit ROOM;

void create ()
{
  set ("short", "玉阶");
  set ("long", @LONG

由此向上是龙宫正殿，东海龙王就住在里面。一级级的台阶都是用　　　
玉砌成，阶上两边立着武士，银盔银甲，煞是威风。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "eastup" : __DIR__"inside3.c",
  "westdown" : __DIR__"yujie3.c",
]));
//      
        set("water", 1);
//  
  setup();
}
