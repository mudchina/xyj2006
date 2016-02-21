// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "履店");
  set ("long", @LONG

这里是凤仙郡一家颇有名气的鞋店，专售各式各样布履草鞋木
屐皮靴，另外代售一些巾帕之类的用品。店里已无货物，据说
主人已出任求雨法师，由堂弟暂管铺面。
    
LONG);

  set("exits", ([
        "south"    : __DIR__"jiedao3",
      ]));
  set("objects", ([
        __DIR__"npc/sg4" : 1,
      ]));
  setup();
}

