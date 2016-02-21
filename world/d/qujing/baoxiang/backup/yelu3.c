// created by snowcat.c 10/14/1997
// room: /d/qujing/baoxiang/yelu3.c

inherit ROOM;

void create ()
{
  set ("short", "野路");
  set ("long", @LONG

野路道路细长崎岖，起伏不停。四周远远都是大小山峦，低洼处
是一片湿湿的沼泽地带，看不见人间烟火。走在山路上静悄悄，
雾气浓郁，不由得让人小心加快步伐。

LONG);

  set("exits", ([
        "northwest"  : __DIR__"yelu2",
        "northup"    : __DIR__"shan1",
        "southeast"  : __DIR__"shanwan2",
      ]));
  set("outdoors","/d/qujing/baoxiang");

  setup();
}

