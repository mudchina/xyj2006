// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "大院");
  set ("long", @LONG

大院方方正正，院墙高大用山石砌成。西边靠墙根有一排松树，
树前开出一片空地，供演武之用。东边有门通向几位王子的府
楼，南边是正府。

LONG);

  set("exits", ([
        "north"   : __DIR__"fumen",
        "south"   : __DIR__"zheng",
        "east"   : __DIR__"da",
      ]));
  set("outdoors", __DIR__);

  setup();
}



