// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "寡妇店");
  set ("long", @LONG

寡妇店乃是一家客店，门前挑着一招牌，绣着“赵家寡妇店”
五个大字。店堂内一尘不染，有一些床铺靠墙而放，床与床之
间以布屏隔开。

LONG);

  set("exits", ([
        "east"    : __DIR__"jiedao8",
        "west"    : __DIR__"tianjing",
      ]));
  set("objects", ([
        __DIR__"npc/guafu"    : 1,
      ]));
  set("sleep_room",1);
  set("if_bed",1);
  setup();
}

