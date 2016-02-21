// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "宫门");
  set ("long", @LONG

宫门霞飞虹飘，各色旌旗迎风招扬，门上架着一巨大的飞檐，
下面是双曲汇彩回廊，由九根红柱撑住。北面有一栅栏门，东
面是殿阁。

LONG);

  set("exits", ([
        "west"    : __DIR__"qiankun",
        "north"    : __DIR__"junying",
        "east"    : __DIR__"jinluan",
      ]));
  set("objects", ([
        __DIR__"npc/junshi"    : 2,
      ]));
  setup();
}

int valid_leave (object who, string dir)
{
  if (! interactive (who) &&
      dir == "east")
    return 0;
  return ::valid_leave(who,dir);
}
