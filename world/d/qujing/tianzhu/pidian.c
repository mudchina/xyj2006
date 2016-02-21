// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "皮店");
  set ("long", @LONG

皮店里摆了一个长长的桌子，上面放了各式各样的皮衣皮靴。
墙上的木架上也挂了一些兽皮衣兽皮帽，门口有一把椅子，也
摆满了皮货。

LONG);

  set("exits", ([
        "south"   : __DIR__"jiedao92",
      ]));
  set("objects", ([
        __DIR__"npc/shu"   : 1,
      ]));

  setup();
}


