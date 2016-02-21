//Cracked by Roath

//  妖神之争 １。０
//  by happ@YSZZ 2000.4.6
//  /d/qujing/yunzhan/road5.c

inherit ROOM;

void create ()
{
  set ("short", "山路");
  set ("long", @LONG

一路上，红花绿草逐渐多了起来，泉水在叮咚的奔流，鸟儿在
天空尽情的歌唱，再往前走，你就要走进了一片山林。
LONG);

  set("exits", ([
        "east"  : __DIR__"road4",
        "westup"  : __DIR__"shanlu1",
      ]));
  set("outdoors","yz");
  setup();
}
