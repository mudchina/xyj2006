// create by snowcat jan 21 1998

inherit ROOM;

void create ()
{
  set ("short", "香兰亭");
  set ("long", @LONG

香兰亭里种满了鲜花异草，香味缭绕令人陶然。南边有一桃木案，上
有无数盆兰花草。亭子的西面有一彩珠帘通往兰亭府大门，北面有道
通向玉兰亭。

LONG);

  set("exits", ([
        "west" : __DIR__"lanting",
        "north" : __DIR__"yulan",
      ]));
  set("objects", ([
        __DIR__"npc/yahuan" :  1,
        __DIR__"npc/xianglan" :  1,
      ]));

  setup();
}


