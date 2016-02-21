// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "方丈");
  set ("long", @LONG

方丈室明亮宽敞，南边有一斗窗，窗下有一木制经桌，桌上放
着经书木鱼木锤之类。北边有一小茶桌，边上几把木椅木凳。
东边有一门通向宝殿下。

LONG);

  set("exits", ([
        "east"   : __DIR__"baodian",
      ]));
  set("objects", ([
        __DIR__"npc/fang"   : 1,
      ]));

  setup();
}


