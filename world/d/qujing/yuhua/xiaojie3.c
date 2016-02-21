// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "小街");
  set ("long", @LONG

一条由碎石夯实的小街。小街有丈许宽，两边走着一些行人，
街上不时有马车驶过。东面传来一阵一阵的歌声，西边飘来饭
菜的香味。

LONG);

  set("exits", ([
        "north"   : __DIR__"xiaojie2",
        "south"   : __DIR__"xiaojie4",
        "east"   : __DIR__"geguan",
        "west"   : __DIR__"jiulou",
      ]));
  set("objects", ([
        __DIR__"npc/people"  : 2,
      ]));
  set("outdoors", __DIR__);

  setup();
}



