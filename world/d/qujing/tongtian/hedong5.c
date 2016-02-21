// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "河东");
  set ("long", @LONG

一条很宽的大河横在面前，一眼望去，远远可以见到隐约的对
岸。河堤的背面就是陈家庄，河面已结了厚厚的一层冰，偶然
见到一些人行走在冰上。

LONG);

  set("exits", ([
        "north"   : __DIR__"hedong4",
        "south"   : __DIR__"hedong6",
      ]));
  set("outdoors", __DIR__);

  setup();
}



