// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "民居");
  set ("long", @LONG

民居里十分热闹，两张大木桌子拼在一起，周围放着椅子凳子，
几个近邻凑在一起，围桌而坐，不知在谈什么。屋角的灶上烧
着热水发出吱吱的水响。

LONG);

  set("exits", ([
        "out"   : __DIR__"chen3",
      ]));
  set("objects", ([
        __DIR__"npc/people"  : random(3)+3,
      ]));

  setup();
}



