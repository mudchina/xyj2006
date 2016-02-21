// create by snowcat jan 21 1998

inherit ROOM;

void create ()
{
  set ("short", "玉兰亭");
  set ("long", @LONG

玉兰亭里面色彩幽明，靠西的墙边有一红花柜，几盆吊兰草从上垂下
来。东边有一方书桌，上面有一个雕花笔筒一方宝砚。亭子南边是香
兰亭，北面有道通向翠兰亭。

LONG);

  set("exits", ([
        "north" : __DIR__"cuilan",
        "south" : __DIR__"xianglan",
      ]));
  set("objects", ([
        __DIR__"npc/yahuan" :  1,
//        __DIR__"npc/yulan" :  1,
      ]));

  setup();
}


