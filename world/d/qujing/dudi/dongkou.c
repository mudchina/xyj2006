// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "洞口");
  set ("long", @LONG

一个藤蔓丛生的山崖深处出现一个洞口，洞里冒着雾气，如袅
袅的白烟一般。高高的石崖上刻着六个醒目的大字：“毒敌山
琵芭洞”，往东南方向有一入口。

LONG);

  set("exits", ([
        "southwest"   : __DIR__"dudi2",
        "enter"   : __DIR__"yidong",
      ]));
  set("outdoors", __DIR__);

  setup();
}



