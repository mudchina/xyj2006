// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "寝宫");
  set ("long", @LONG

寝宫里陈列着百鸟绣花图，四周是常春花卉。窗外滴水潺潺，
屋内香火缈缈，放着几只精制紫色香木几，中间是双枕鹅绒软
褥宫床。

LONG);

  set("exits", ([
        "north"    : __DIR__"fenggong",
        "northwest"    : __DIR__"longgong",
      ]));
  set("objects", ([
        __DIR__"npc/girl"    : 1,
      ]));
  set("sleep_room",1);
  set("if_bed",1);
  setup();
}

