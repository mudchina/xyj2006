// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "石路");
  set ("long", @LONG

山外上一条石子路绕来绕去，沿着地势略有些起伏。石路边荒
芜人烟青草丛生古树盘根错节，不知通向何处。远处有风低低
的吼叫，古树有野鸦呱呱。

LONG);

  set("exits", ([
        "southwest"   : __DIR__"shilu2",
        "north"	: "/d/qujing/tianzhu/dalu5",
      ]));
  set("outdoors", __DIR__);

  setup();
}



