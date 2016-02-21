// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "小街");
  set ("long", @LONG

一条由碎石夯实的小街。小街有丈许宽，两边走着一些行人，
街上不时有马车驶过。小街的东面有座营房，北面是门楼通向
郊外。

LONG);

  set("exits", ([
        "north"   : __DIR__"menlou",
        "south"   : __DIR__"xiaojie2",
        "east"   : __DIR__"shaoying",
      ]));
  set("objects", ([
        __DIR__"npc/people"  : 2,
      ]));
  set("outdoors", __DIR__);

  setup();
}



