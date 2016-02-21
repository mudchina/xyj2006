// rewritten by snowcat on 4/11/1997
// Room: shalu2

inherit ROOM;

void create ()
{
  set ("short", "砂砾径");
  set ("long", @LONG

小径往东是一片绿洲，往西通向山里，站在小径边上，已经可以感
觉到山上的热浪一阵阵地涌来。

LONG);

  set("exits", ([
        "west" : __DIR__"shalu",
        "east" : __DIR__"luzhou",
      ]));
  set("outdoors", "firemount");

  setup();
}
