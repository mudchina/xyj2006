// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "小街");
  set ("long", @LONG

一条由碎石夯实的小街。小街有丈许宽，两边走着一些行人，
街上不时有马车驶过。街的南面有一群楼阁，那里便是王府所
在地。

LONG);

  set("exits", ([
        "north"   : __DIR__"xiaojie4",
        "south"   : __DIR__"fumen",
        "east"   : __DIR__"xiaojie8",
        "west"   : __DIR__"xiaojie6",
      ]));
  set("outdoors", __DIR__);

  setup();
}



