// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/jiuguan.c

inherit ROOM;

void create ()
{
  set ("short", "酒馆");
  set ("long", @LONG

小酒馆里边酒柜齐胸高。后面可以看见三个大酒缸。墙上挂着一
些酒葫芦酒袋，案桌上放着大块的熟牛肉。酒保一边招待客人，
一边切着熟牛肉。

LONG);

  set("exits", ([
        "east"         : __DIR__"caichang",
      ]));

  set("objects", ([
         __DIR__"npc/jiubao" : 1,
      ]));

  setup();
}

