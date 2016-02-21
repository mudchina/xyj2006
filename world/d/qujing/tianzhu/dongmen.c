// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "东门");
  set ("long", @LONG

一条长长的护城河出现在眼前，有两丈多深，上面架着一巨大
的铁链木桥。桥头是一高大的城楼，用山石砌成，楼顶上有了
望哨。城楼书有三个大字：天竺国。

LONG);

  set("exits", ([
        "east"   : __DIR__"dalu2",
        "west"   : __DIR__"jiedao57",
        "north"   : __DIR__"jiedao48",
        "south"   : __DIR__"jiedao68",
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
      dir == "east")
    return 0;
  return ::valid_leave (who, dir);
}

