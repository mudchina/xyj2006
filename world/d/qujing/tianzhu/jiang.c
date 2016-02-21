// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "酱房");
  set ("long", @LONG

酱房里远远就能闻到酱菜的味道，里面放着一溜子大腌缸，缸
里泡着各式酱菜腌菜，菜上面用青石板压着出水，上面再用木
盖将缸盖严。

LONG);

  set("exits", ([
        "east"   : __DIR__"jiedao71",
      ]));
  set("objects", ([
        "/d/obj/food/salt" : 2,
      ]));

  setup();
}


