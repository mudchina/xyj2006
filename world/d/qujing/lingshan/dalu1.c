//Cracked by Roath
// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "大路");
  set ("long", @LONG

大路两边，有琪花，瑶草，古柏，苍松。果然一个西方佛地，
与他处不同。不时可见路边有人或是停在路边修道，或是闭目
诵经。

LONG);

  set("exits", ([
        "east"   : __DIR__"dalu2",
        "south"   : __DIR__"shanjiao",
      ]));
  set("objects", ([
        __DIR__"npc/people" : 1+random(3),
      ]));
  set("outdoors", __DIR__);

  setup();
}



