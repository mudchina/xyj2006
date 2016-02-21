// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "大王子府");
  set ("long", @LONG

大王子府碧灯盏盏，一镶银桌上放着玉如意之类的贵重玩意。
桌后一高背太师椅，椅前有狮绒垫脚。南窗外可见一小桥曲曲
弯弯有水流过。

LONG);

  set("exits", ([
        "west"   : __DIR__"dayuan",
        "east"   : __DIR__"er",
      ]));
  set("objects", ([
        __DIR__"npc/dianguan"  : 2,
        __DIR__"npc/prince1"  : 1,
      ]));

  setup();
}



