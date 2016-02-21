// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "小街");
  set ("long", @LONG

一条由碎石夯实的小街。小街有丈许宽，两边走着一些行人，
街上不时有马车驶过。小街的南面远远可见一府门，北面远远
可见一门楼。

LONG);

  set("exits", ([
        "north"   : __DIR__"xiaojie3",
        "south"   : __DIR__"xiaojie7",
      ]));
  set("objects", ([
        __DIR__"npc/people"  : 2,
      ]));
  set("outdoors", __DIR__);

  setup();
}



