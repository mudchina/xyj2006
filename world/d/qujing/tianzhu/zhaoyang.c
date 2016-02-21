// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "昭阳宫");
  set ("long", @LONG

昭阳宫里紫气袅袅，正面是一绘金玉边彩屏，有数丈之宽光照
逼人。宫东西两边是缤纷百花窗，几条绛红色大帘如瀑一般从
彩墙壁上披下来，天花板上吊着的华灯齐放。

LONG);

  set("exits", ([
        "south"   : __DIR__"wumen",
        "east"   : __DIR__"gongyuan",
        "north"   : __DIR__"jinluan",
      ]));
  set("objects", ([
        __DIR__"npc/taijian"   : 2,
      ]));

  setup();
}


