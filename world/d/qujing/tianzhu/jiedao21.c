// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "街道");
  set ("long", @LONG

街道上人来人往，两边是各式各样的商店铺面酒馆药房等等，
应有尽有。五花八门的招牌幡旗临街挑起，不时可听见贩子们
的吆喝声从街上传来。

LONG);

  set("exits", ([
        "north"   : __DIR__"jiedao11",
        "east"   : __DIR__"jiuguan",
        "west"   : __DIR__"kedian",
        "south"   : __DIR__"jiedao31",
      ]));
  set("objects", ([
        __DIR__"npc/people"   : 1,
      ]));
  set("outdoors", __DIR__);

  setup();
}



