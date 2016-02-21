//Cracked by Roath
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.7
//  /d/qujing/huangfeng/shanlu3.c

inherit ROOM;

void create ()
{
  set ("short", "山路");
  set ("long", @LONG

路上那些野兽都是成双成对的出来，一个眼睛烁烁放光，一看
就知道这个山里面的妖怪为数不少。
LONG);

  set("exits", ([
        "westup"  : __DIR__"dongkou",
        "eastdown"  : __DIR__"shanlu3",
      ]));
  set("outdoors","hfd");
  setup();
}
