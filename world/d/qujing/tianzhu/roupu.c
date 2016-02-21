// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "肉铺");
  set ("long", @LONG

一个大棚子里放着一个厚木桌，上面有一肉砧板。桌子后面有
个木盆，里面大概是大块大块的生肉。棚子一边挂着一只猪头
一边挂着一只牛头。

LONG);

  set("exits", ([
        "west"   : __DIR__"jiedao75",
      ]));
  set("objects", ([
        __DIR__"npc/qiao"   : 1,
      ]));

  setup();
}


