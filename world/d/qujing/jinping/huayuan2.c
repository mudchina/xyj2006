// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "花园");
  set ("long", @LONG

一个花亭在花园中心小巧玲珑地建着，两边有小径，径外是一
片又一片的花圃，种着牡丹芍药海棠腊梅菊花等等。花圃的后
面可以看见一大片果园，上面果实累累。

LONG);

  set("exits", ([
        "west"   : __DIR__"huayuan1",
        "south"   : __DIR__"huayuan3",
      ]));
  set("outdoors", __DIR__);

  setup();
}



