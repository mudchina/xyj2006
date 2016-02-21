//Cracked by Roath
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.5
//  /d/qujing/heifeng/road3.c

inherit ROOM;

void create ()
{
  set ("short", "山路");
  set ("long", @LONG

这里是一片黑亚亚的松林，光线非常的暗，只能看到前方出口处
的一点亮光，不时还传来一两声猫头鹰的嘶叫声。

LONG);

  set("exits", ([
        "south"  : __DIR__"dongkou",
        "north"  : __DIR__"road4",
      ]));
  set("outdoors","hf");
  setup();

}
