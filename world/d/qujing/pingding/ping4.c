// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "平顶山");
  set ("long", @LONG

山岭巍峨起伏，峰顶气势缓平，天边泛起一层彩霞，云雾之中
遍野林海更加郁郁苍苍。在这里道路平坦，路边有小灌木一丛
一丛，古树萧萧。

LONG);

  set("exits", ([
        "north"   : __DIR__"ping3",
        "northwest"   : __DIR__"ping2",
      ]));
  set("outdoors", __DIR__);

  setup();
}



