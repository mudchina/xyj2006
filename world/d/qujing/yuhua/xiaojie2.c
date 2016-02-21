// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "小街");
  set ("long", @LONG

一条由碎石夯实的小街。小街有丈许宽，两边走着一些行人，
街上不时有马车驶过。小街的西面传来打铁的声音，门口挂一
杆招牌。

LONG);

  set("exits", ([
        "north"   : __DIR__"xiaojie1",
        "south"   : __DIR__"xiaojie3",
        "west"   : __DIR__"tiejiang",
      ]));
  set("objects", ([
        __DIR__"npc/people"  : 2,
      ]));
  set("outdoors", __DIR__);

  setup();
}



