inherit ROOM;

void create ()
{
  set ("short", "廊道");
  set ("long", @LONG

走廊的两旁站立着泥像，廊顶的琉璃盏里的
灯火照亮了前方的路。
LONG);

  set("exits", ([
        "out" : __DIR__"shanmen",
        "north" : __DIR__"langdao2",
      ])); 

  setup();
}

