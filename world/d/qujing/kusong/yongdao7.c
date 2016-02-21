//Cracked by Roath
inherit ROOM;

void create ()
{
  set ("short", "甬道");
  set ("long", @LONG

甬道内发出一股血腥气。墙上挂着油灯，忽明忽暗的灯光隐隐照
出了前后的道路。
LONG);
  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"huoyun", 
  "south" : __DIR__"zhongdong",
]));

  set("objects", ([ /* sizeof() == 1*/
  __DIR__"npc/yao2" : 2,    
]));


  setup();
}

