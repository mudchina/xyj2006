// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "花园");
  set ("long", @LONG

花园里有一条小径，小径两边是花圃，种着牡丹芍药海棠腊梅
菊花等等。花圃的后面是果实累累的寺内果园，西边有门通向
正殿。

LONG);

  set("exits", ([
        "north"   : __DIR__"huayuan2",
        "west"   : __DIR__"zheng",
        "east"   : __DIR__"xiaolu",
      ]));
  set("outdoors", __DIR__);

  setup();
}



