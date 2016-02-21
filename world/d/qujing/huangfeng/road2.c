//Cracked by Roath
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.7
//  /d/qujing/huangfeng/road1.c

inherit ROOM;

void create ()
{
  set ("short", "乡间小路");
  set ("long", @LONG

路边的一排排小茅屋排列的错落有致，这些茅屋旁边一般都种些大树，
一到夏天就可以到树下乘凉，有的屋前还挂些腌制的兽肉。
LONG);

  set("exits", ([
        "west"  : __DIR__"road3",
        "east"  : __DIR__"road1",
      ]));
  set("outdoors","hfd");
  setup();
}
