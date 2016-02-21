// room: /d/qujing/baoxiang/yelu4.c moved to baigudong by smile 12/10/1998

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
        "west"       : "/d/qujing/baoxiang/shanwan1",
        "east"       : __DIR__"yelu5",
      ]));
  set("outdoors",__DIR__"");

  setup();
}

