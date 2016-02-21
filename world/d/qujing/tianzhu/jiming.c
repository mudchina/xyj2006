// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "鸡鸣关");
  set ("long", @LONG

山路在这里变得狭窄，两边是高高的山岩，看上去如一天然的
屏障。路的一边长有一片片的灌木丛，另一边长着齐胸高的野
蒿草随风摇戈。

LONG);

  set("exits", ([
        "north"   : __DIR__"shan1",
        "southeast"   : __DIR__"shan2",
      ]));
  set("outdoors", __DIR__);

  setup();
}



