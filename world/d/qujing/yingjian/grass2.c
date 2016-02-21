//Cracked by Roath
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.3
//  /d/qujing/yingjian/xiaolu1.c

inherit ROOM;

void create ()
{
  set ("short", "草丛");
  set ("long", @LONG

这里到处都是草，有的草比人还要高，人在其间根本看不到外面。
听说这些草从里面经常会出现一些野兽什么的。
LONG);

  set("exits", ([
        "east"  : __DIR__"lakeside3",
        "west"  : "/d/qujing/heifeng/shanlu1",
      ]));
  setup();

}
