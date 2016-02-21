// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "肉库");
  set ("long", @LONG

一座由岩洞自然形成的洞穴，里面有些阴暗，地上铺着兽皮干
草，还有一些七零八落的骨头。洞壁靠有一长架子，上有不少
肉干肉巴子。

LONG);

  set("exits", ([
        "northwest"    : __DIR__"bopiting",
      ]));
  set("objects", ([
        __DIR__"obj/rou" : 8,
      ]));
  setup();
}

