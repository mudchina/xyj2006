// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "二王子府");
  set ("long", @LONG

二王子府蓝色落地绒罩着北墙，墙角有一雕玉狩猎图花屏，西
边有一软躺椅，边上是蚂瑙纹茶几。南窗紧闭，隐约可见窗外
杨柳拂栏杆。

LONG);

  set("exits", ([
        "west"   : __DIR__"da",
        "east"   : __DIR__"xiao",
      ]));
  set("objects", ([
        __DIR__"npc/dianguan"  : 2,
        __DIR__"npc/prince2"  : 1,
      ]));

  setup();
}



