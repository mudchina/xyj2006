// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "暴纱亭");
  set ("long", @LONG

一座可供十来人休息的绿亭，亭外流水潺潺，有一泉水环绕一
假山而过。不远处杨柳轻飘，水面上有一小桥曲曲弯弯，景色
极为怡人。

LONG);

  set("exits", ([
        "northeast"   : __DIR__"zheng",
      ]));

  setup();
}



