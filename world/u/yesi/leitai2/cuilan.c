// create by snowcat jan 21 1998

inherit ROOM;

void create ()
{
  set ("short", "翠兰亭");
  set ("long", @LONG

翠兰亭里飘着一股清香味，北边的亭角挂着一只鸟笼，里面的鸟儿正
唱着歌。亭柱上挂着一幅细竹山水画，亭东有一竹桌竹椅。南边是通
往玉兰亭的门。

LONG);

  set("exits", ([
        "south" : __DIR__"yulan",
      ]));
  set("objects", ([
        __DIR__"npc/yahuan" :  1,
//        __DIR__"npc/cuilan" :  1,
      ]));

  setup();
}


