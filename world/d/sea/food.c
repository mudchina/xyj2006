// Room: /d/sea/food.c
inherit ROOM;

void create ()
{
  set ("short", "餐房");
  set ("long", @LONG

龙宫内的一间餐房，一般只是宫中弟子使用。锅里沽嘟嘟不知煮着什么东
西，一个大箩筐里放着好些包子。

LONG);

  set("objects", ([ /* sizeof() == 3 */
  __DIR__"npc/long6.c" : 1,
  __DIR__"obj/food" : 3,
  "/d/obj/food/niupi-jiudai.c" : 1,
]));

set("resource", ([ /* sizeof() == 1 */
  "water" : 1,
]));

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"mulang1.c",
]));
//      
        set("water", 1);
//  
  setup();
}
