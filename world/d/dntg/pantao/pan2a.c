// created by snowcat.c 5/27/1997
// room: /d/pantao/pan2a.c

inherit ROOM;

void create ()
{
  set ("short", "蟠桃园");
  set ("long", @LONG

蟠桃园内花红叶绿，夭夭灼灼花盈树，颗颗枝枝果压枝。只见
是：时开时结千年熟，无夏无冬万载迟，先熟的，酡颜醉脸，
还生的，带蒂青皮。好个凝脂肌带绿，映日显丹姿。

LONG);

  set("exits", ([
        "northwest"  : __DIR__"ting3",
        "west"       : __DIR__"ting4",
        "southwest"  : __DIR__"ting5",
        "east"       : __DIR__"pan2b",
      ]));

  set("outdoors",1);
  setup();
}

