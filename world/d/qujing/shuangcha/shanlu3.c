//Cracked by Roath
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.3
//  /d/qujing/shuangcha/shanlu3.c

inherit ROOM;

void create ()
{
  set ("short", "山岭");
  set ("long", @LONG

这个地方已经可以看到很明显的出路了，景色变的优美多了，
两旁的树林飒飒作响，到处都是些路两旁都开些野花，石头
堆砌多变，让人感到天工的神笔。
LONG);

  set("exits", ([
        "eastdown" : __DIR__"shanlu2",
        "west"   : __DIR__"on",
      ]));
  set("outdoors","sc");
  setup();
}
