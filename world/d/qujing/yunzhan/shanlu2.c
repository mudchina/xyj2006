//Cracked by Roath

//  妖神之争 １。０
//  by happ@YSZZ 2000.4.6
//  /d/qujing/yunzhan/shanlu2.c

inherit ROOM;

void create ()
{
  set ("short", "山路");
  set ("long", @LONG

你走在一片树荫中，由于树叶繁茂，把整个天空都遮住了，林中
显得特别的阴暗和潮湿。地面也全部被落叶盖了一层。

LONG);

  set("exits", ([
        "eastdown"  : __DIR__"shanlu1",
        "westup"  : __DIR__"shanlu3",
      ]));
  set("outdoors","yz");
  setup();
}
