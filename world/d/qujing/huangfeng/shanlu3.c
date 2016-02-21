//Cracked by Roath
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.7
//  /d/qujing/huangfeng/shanlu3.c

inherit ROOM;

void create ()
{
  set ("short", "山路");
  set ("long", @LONG

走到山路上，看着远方的丛山，你觉得此山真是个险啊，山峰迭障
不断，山路起浮崎岖，路旁尽是些奇石怪木。
LONG);

  set("exits", ([
        "westup"  : __DIR__"shanlu4",
        "eastdown"  : __DIR__"shanlu2",
      ]));
  set("outdoors","hfd");
  setup();
}
