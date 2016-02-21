// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "成衣店");
  set ("long", @LONG

成衣店里挂着五颜六色的衣裳袍裙，衣服多种多样，各种艳丽
朴素花色应有尽有。一排排地从屋前的绳子上挂到屋后，有不
少人在此挑选合适的衣服。

LONG);

  set("exits", ([
        "south"   : __DIR__"jiedao96",
      ]));
  set("objects", ([
        __DIR__"npc/tao"   : 1,
      ]));

  setup();
}


