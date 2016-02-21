// Room: /4world/houshan4

inherit ROOM;

void create ()
{
  set ("short", "桃树林");
  set ("long", @LONG

桃树林中。黄澄澄的猕猴桃显然已经熟透，已经有一些从树上
掉了下来。一阵果香飘来，你口水都流了出来。
LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/d/obj/drug/mihoutao" : 2,
  __DIR__"npc/liuer-mihou" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"houshan3",
]));

  setup();
}
