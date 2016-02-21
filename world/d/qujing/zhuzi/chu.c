// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "厨房");
  set ("long", @LONG

一口泥灶砌在墙边，柴禾堆放在灶边。灶上是一大铁锅，两只水桶
放在旁边。靠墙有一柜子，放着一些青瓷碗细竹筷。

LONG);

  set("exits", ([ 
    "west" : __DIR__"huitong",
  ]));
  setup();
}
