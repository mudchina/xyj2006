// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "中市");
  set ("long", @LONG

中市为一片开阔地带，附近的楼阁平房已被拆卸一空，东南面
原有一红殿庙宇不知何故被推倒，只剩下残砖剩瓦。正东是一
座城楼，南北两边各有一广场，西面有长长的街道。

LONG);

  set("exits", ([
        "north"    : __DIR__"beishi",
        "south"    : __DIR__"nanshi",
        "east"    : __DIR__"dongmen",
        "west"    : __DIR__"jiedao7",
      ]));
  set("outdoors",__DIR__"");
  setup();
}

