// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "西门");
  set ("long", @LONG

一条长长的护城河出现在眼前，有两丈多深，上面架着一巨大
的铁链木桥。桥头是一高大的城楼，用山石砌成，楼顶上有了
望哨。城楼书有三个大字：天竺国。

LONG);

  set("exits", ([
        "west"   : __DIR__"dalu1",
        "east"   : __DIR__"jiedao52",
        "north"   : __DIR__"jiedao41",
        "south"   : __DIR__"jiedao61",
      ]));
  set("objects", ([
        __DIR__"npc/bing"   : 2,
      ]));
  set("outdoors", __DIR__);

  setup();
}

int valid_leave (object who, string dir)
{
  if (! interactive (who) &&
      who->query("people") == "people" &&
      dir == "west")
    return 0;
  return ::valid_leave (who, dir);
}

