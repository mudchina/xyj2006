inherit ROOM;

void create ()
{
  set ("short", "幕府");
  set ("long", @LONG

幕府是龙宫中虾兵蟹将各类水怪休息的地方。厅前挂着又厚又高的　　　
帘子，将其于前厅分开。堂中并无华丽的装饰，但打扫的恨干净。　　　
有几个宫娥出出入入。
LONG);
          set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/gonge" : 1,
]));


  set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"qingxin",
  "east" : __DIR__"food.c",
]));
//      
        set("water", 1);
//  
  setup();
}

