// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "内院");
  set ("long", @LONG

内院里细石如碎玉铺地，东南角几棵梧桐临月台而植，东北君子竹
翠绿似画。西边有莲花道通向正宫，东边则是牡丹芍药花圃一路延
向内宫，东南处有霜叶松引向后三宫。

LONG);

  set("exits", ([ /* sizeof() == 1 */
    "west" : __DIR__"zheng",
    "east" : __DIR__"nei",
    "southeast" : __DIR__"housan",
  ]));
  set("outdoors", __DIR__"");
  set("objects", ([
      __DIR__"npc/taijian" : 2,
  ]));
  setup();
}
