//Cracked by Roath
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.7
//  /d/qujing/huangfeng/road1.c

inherit ROOM;

void create ()
{
  set ("short", "乡间小路");
  set ("long", @LONG

慢慢的，你走出了山林，这里是乡间的小路上，这的风景完全和山里
不一样，路边的篱笆整整齐齐的排列着，里面都种些白菜一类的蔬菜
，散发出蔬菜特有的清新。
LONG);

  set("exits", ([
        "west"  : __DIR__"road2",
        "eastup"  : "/d/qujing/yunzhan/shanlu3",
      ]));
  set("outdoors","hfd");
  setup();
}
