inherit ROOM;

void create ()
{
  set ("short", "望月谷");
  set ("long", @LONG

两边的小山对立，这里形成了一个弯月状的山谷。谷中开着许
多不知名的野花，看起来十分的悠雅安静。谷的北面有一片白
汪汪的水泽。
LONG);
  set("exits", ([ /* sizeof() == 4 */
  "southwest" : __DIR__"jiandi2",
  "north" : __DIR__"baihu", 
]));

  set("objects", ([ /* sizeof() == 1*/
  __DIR__"obj/qixingcao" : 1,
  __DIR__"obj/jinyinguo" : 1,    
  __DIR__"obj/xuanhuang" : 1,
]));

  set("outdoors", 1);


  setup();
}

