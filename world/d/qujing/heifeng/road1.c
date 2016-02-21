//Cracked by Roath
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.3
//  /d/qujing/heifeng/shanlu1.c

inherit ROOM;

void create ()
{
  set ("short", "山路");
  set ("long", @LONG

这一带的山路上尽是些竹子，风一吹，竹叶挲挲做响，路上到处
都是些落下的竹叶。
LONG);

  set("exits", ([
        "northwest"  : __DIR__"shanmen3",
        "south"      : __DIR__"road2",
      ]));
  set("outdoors","hf");
  setup();

}
