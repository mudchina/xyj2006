//Cracked by Roath
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.5
//  /d/qujing/heifeng/cave.c

inherit ROOM;

void create ()
{
  set ("short", "正台");
  set ("long", @LONG

这是整个山洞最高的地方，无数小妖精都梦想着有一天可以自己
等上高台，发号施令，那是何等的威风。正台的两侧具然还有盆
景，真是让是不可思意。
LONG);

  set("exits", ([
        "northdown"  : __DIR__"in2",
      ]));
  setup();
}
