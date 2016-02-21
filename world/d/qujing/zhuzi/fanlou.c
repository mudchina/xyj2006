// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "饭楼");
  set ("long", @LONG

饭楼靠街有一两个很高很小的窗子，里面灯火通明，客人满席，正
在有滋有味地吃饭喝汤。几面屏风将整个屋子分成雅俗几个不同等
级的席位，北边是夕林街。

LONG);

  set("exits", ([ 
    "north" : __DIR__"xi2",
  ]));
  set("objects", ([
    __DIR__"npc/wan" : 1,
  ]));
  setup();
}
