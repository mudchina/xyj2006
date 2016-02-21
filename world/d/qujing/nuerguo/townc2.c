// created by snowcat.c 4/4/1997
// room: /d/nuerguo/townc2.c

inherit ROOM;

void create ()
{
  set ("short", "桑花巷中");
  set ("long", @LONG

你走在西梁镇的桑花巷中，这是西梁女国的主要城镇。镇子
不大，镇子里的老老少少都是女人。见到有外边的游客来，
尤其是男游客，女人们都惊喜地拥上街头叽叽喳喳嘻嘻哈哈
地议论个不停。

LONG);

  set("exits", ([
        "north" : __DIR__"townb2",
        "west"  : __DIR__"townc1",
        "east"  : __DIR__"townc3",
      ]));
  set("outdoors", __DIR__"");

  setup();
}






