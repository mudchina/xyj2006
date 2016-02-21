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
  "north" : __DIR__"kitchen", 
  "south" : __DIR__"weapon",
  "west" : __DIR__"zhongdong",
  "east" : __DIR__"xingfang",
]));

  set("objects", ([ /* sizeof() == 1*/
  __DIR__"npc/yao1" : 1,    
]));


  setup();
}

