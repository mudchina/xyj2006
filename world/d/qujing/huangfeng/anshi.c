// created by wxb 12/24/1998
// room: /d/qujing/huangfeng/anshi.c

inherit ROOM;

void create ()
{
  set ("short", "暗室");
  set ("long", @LONG

光线朦胧，风雨不通。你只觉得心跳加快，气闷难耐。这里看
起来像是黄风山的小妖们休息的地方。只有东边有小洞通住外
面。

LONG);

  set("exits", ([
        "east"         : __DIR__"dong6",
      ]));

  set("objects", ([
      ]));
  set("sleep_room",1);
  set("if_bed",1);
  setup();
}

