//Cracked by Roath
// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "珍楼");
  set ("long", @LONG

楼里摆满了各种玉盆香花琼草，中间有一翡翠仙桌，边上摆着
檀香嵌玉软椅。桌上摆着一些大小金盘银盘，里面是仙品、仙
茶、仙果。

LONG);

  set("exits", ([
        "down"   : __DIR__"zhenlou1",
      ]));
  set("objects", ([
        __DIR__"obj/cha" : 2,
        __DIR__"obj/guo" : 2,
        __DIR__"npc/xiantong" : 2,
     ]));

  setup();
}

