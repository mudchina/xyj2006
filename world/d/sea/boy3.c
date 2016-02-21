// boy3.c

inherit ROOM;

void create ()
{
  set ("short", "卧龙阁");
  set ("long", @LONG

当中一个八仙桌，桌上摆的都是些山珍海味。太子正和几个朋友
喝酒。宫女们来回上菜，屋中一片酒味。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"boy2",
]));
  set("objects", ([ /* sizeof() == 3 */
  __DIR__"npc/long2.c" : 1,
  __DIR__"npc/longshao" : 1,
  __DIR__"npc/biaodi" : 1,
]));
//      
        set("water", 1);
//  
  setup();
}
