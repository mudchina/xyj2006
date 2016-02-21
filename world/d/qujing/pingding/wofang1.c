// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "卧房");
  set ("long", @LONG

卧房的地上铺着野草干花，南边的石壁前有一红木桌，上面点
着一盏青玉灯，北边的石壁上有一石龛。卧房的西边有一走廊
通往内殿。

LONG);

  set("exits", ([
        "west"   : __DIR__"neidian",
      ]));
  set("objects", ([
        __DIR__"npc/yao2"   : 2,
        __DIR__"npc/laonai"   : 1,
        __DIR__"obj/food"   : 3,
      ]));

  setup();
}


