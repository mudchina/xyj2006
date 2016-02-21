// Room: /u/rainy/sea/yidao.c
inherit ROOM;

void create ()
{
  set ("short", "仪道");
  set ("long", @LONG

这里是花园中的一条小道，看周围的情形并不是经常有人来。路上　　　
铺着细小的白色石子，高处有草木掩映。弯弯的仪道通向四周，向　　　
西就回到了后厅。

LONG);

  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"jiashan2.c",
  "north" : __DIR__"jiashan1.c",
  "west" : __DIR__"inside4",
  "east" : __DIR__"shiwu.c",
]));
//      
        set("water", 1);
//  
  setup();
}
