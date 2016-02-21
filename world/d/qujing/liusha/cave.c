//Cracked by Roath
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.7
//  /d/qujing/liusha/dadao1

inherit ROOM;

void create ()
{
  set ("short", "洞内");
  set ("long", @LONG

这是一个黑悠悠的泥洞，洞内的水竟然是红色的，与人血差不多，
洞底的泥面竟然是一堆堆白骨，有的还连着血肉。洞的左边坐着一
个红发，蓝脸的妖精，手里正捧着一个未吃尽的人头！

LONG);
  set("exits", ([
        "out": __DIR__"dongkou",
        "up": __DIR__"riverside",
        ]));
  set("objects", ([
        __DIR__"npc/sha":1,
        ]));
  setup();
}
