// rewritten by snowcat on 4/11/1997
// room: qujinglu

inherit ROOM;

void create ()
{
  set ("short", "取经路");
  set ("long", @LONG

你陷入一大片荒沙漠的世界，环顾四周，四处都是黄沙，高高低低，
很难从中找出路来。你心里有点紧张。

LONG);

  set("exits", ([
        "northwest" : __DIR__"luzhou3",
        "southeast" : "/d/qujing/dudi/shanlu6",
      ]));
  set("outdoors", "firemount");

  setup();
}
