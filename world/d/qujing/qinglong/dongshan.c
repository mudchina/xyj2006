// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "东山凹");
  set ("long", @LONG

四周一片雾气，有一长练般的瀑布从西山口流下来，冲进东边
的山涧里。这里地势平凹，山涧在脚下打着漩涡流过。西边有
一天然石梯拾级而上。

LONG);

  set("exits", ([
        "southeast"   : __DIR__"shanjian",
        "westup"   : __DIR__"shanlu3",
      ]));
  set("outdoors", __DIR__);

  setup();
}



