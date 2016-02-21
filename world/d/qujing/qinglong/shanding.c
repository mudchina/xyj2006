// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "山顶");
  set ("long", @LONG

站在山顶上望过山脉，一望无际的绿色森林蜿蜒起伏有如一条
长长的青龙，山顶上风大雾多，四周的野兽吼叫声似乎更加近
了一些了。

LONG);

  set("exits", ([
        "southwest"   : __DIR__"shantou",
        "northeast"   : __DIR__"dongkou",
      ]));
  set("outdoors", __DIR__);

  setup();
}



