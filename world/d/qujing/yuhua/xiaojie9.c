// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "小街");
  set ("long", @LONG

一条由碎石夯实的小街。小街有丈许宽，两边走着一些行人，
街上不时有马车驶过。小街的东面有马车停靠，里面是一家官
方的待客馆。

LONG);

  set("exits", ([
        "west"   : __DIR__"xiaojie8",
        "east"   : __DIR__"daike",
      ]));
  set("outdoors", __DIR__);

  setup();
}



