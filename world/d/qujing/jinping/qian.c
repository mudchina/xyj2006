// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "前殿");
  set ("long", @LONG

前殿里粉刷一新，四周墙壁洁亮。殿中有一香台，紫铜的小香
炉里正点着一些香。西边是慈云寺的大门，东边是寺庙的正殿
大堂。

LONG);

  set("exits", ([
        "west"   : __DIR__"shanmen",
        "east"   : __DIR__"zheng",
      ]));
  set("objects", ([
        __DIR__"npc/monk" : 2,
      ]));
  setup();
}



