// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "吊桥");
  set ("long", @LONG

一座城楼耸立，两边是石墙，上有兵士持枪巡逻。墙下有一条
宽宽的护城河床，已经见底了，河上架着铁链吊桥。城楼上有
一牌子：“凤仙郡”。

LONG);

  set("exits", ([
        "north"    : __DIR__"dalu3",
        "south"    : __DIR__"dalu4",
        "west"    : __DIR__"jiedao7",
      ]));
  set("outdoors",__DIR__"");
  setup();
}

int valid_leave (object who, string dir)
{
  if (dir == "west")
    return ::valid_leave (who, dir);

  if (interactive (who))
    return ::valid_leave (who, dir);

  return 0;
}
