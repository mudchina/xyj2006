inherit ROOM;

void create ()
{
  set ("short", "廊道");
  set ("long", @LONG

走廊的两旁站立着泥像，廊顶的琉璃盏里的
灯火照亮了前方的路。
LONG);

 set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/seng" : 1,
        ]));
  set("exits", ([
           "east" : __DIR__"caiyuan",
          "west" : __DIR__"fangzhang",
         "up" : __DIR__"xiuxi",
        "north" : __DIR__"jingge",
        "south" : __DIR__"langdao2",
      ])); 

  setup();
}

