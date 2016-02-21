// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "后宫");
  set ("long", @LONG

后宫门口悬着两排彩灯，宫内绘有金银双凤戏水。内壁处有一玉石
屏风，下有玛瑙梳妆台和一张麒麟床褥。西南朝向有一宫门，由几
位伺女守候着。

LONG);

  set("exits", ([ 
    "southeast" : __DIR__"piangong",
  ]));
  set("objects", ([
    __DIR__"npc/nuyao" : 2,
    __DIR__"npc/queen" : 1,
  ]));
  setup();
}
