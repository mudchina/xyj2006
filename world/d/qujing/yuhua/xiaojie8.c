// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "小街");
  set ("long", @LONG

一条由碎石夯实的小街。小街有丈许宽，两边走着一些行人，
街上不时有马车驶过。街的南面有一厚木楼阁，门口挂有一长
牌：典膳所。

LONG);

  set("exits", ([
        "west"   : __DIR__"xiaojie7",
        "south"   : __DIR__"dianshan",
        "east"   : __DIR__"xiaojie9",
      ]));
  set("outdoors", __DIR__);

  setup();
}



