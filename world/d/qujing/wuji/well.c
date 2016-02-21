// Room: /u/mimi/zhuziguo/well.c  snowcat moved to /d/qujing/wuji
inherit ROOM;

void create ()
{
  set ("short", "井底");
  set ("long", @LONG

这是一口深深的井，沿着井壁上下长满了青苔。井里阴森森，光线
极其黑暗，下面……

LONG);

  set("exits", ([ 
    "up" : __DIR__"yuhua",
    "down" : __DIR__"shuijing",
  ]));

  setup();
}
