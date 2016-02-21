//Cracked by Roath
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.7
//  /d/qujing/village/huanglu.c

inherit ROOM;

void create ()
{
  set ("short", "荒凉小路");
  set ("long", @LONG

这个地方真的叫荒凉，虽然离村庄很近，却有很明显的差别，
四处都是些荒草，根本就没有一线的生机。

LONG);
  set("exits", ([
        "north"  : __DIR__"huanglu3",
        "south"  : __DIR__"huanglu1",
          ]));
  set("outdoors","cz");
  setup();
}
