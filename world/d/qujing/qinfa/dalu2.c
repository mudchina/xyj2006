// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "大路");
  set ("long", @LONG

一条烟尘漫漫的大路，其路遥遥，其雾茫茫，前不见古人后不
见来者。时而有远方兽吼，时而又有近处鸟鸣。两边荒山野林
交替出现，你不由自主地加快步伐。

LONG);

  set("exits", ([
        "west"    : __DIR__"dalu1",
        "east"    : __DIR__"dalu3",
        "south"    : __DIR__"dalu4",
      ]));
  set("outdoors",__DIR__"");
  setup();
}

