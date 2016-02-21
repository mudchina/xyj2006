// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "小街");
  set ("long", @LONG

一条由碎石夯实的小街。小街有丈许宽，两边走着一些行人，
街上不时有马车驶过。小街的西面是一座楼阁，上面挂一个牌
子：长史馆。

LONG);

  set("exits", ([
        "east"   : __DIR__"xiaojie6",
        "west"   : __DIR__"changshi",
      ]));
  set("outdoors", __DIR__);

  setup();
}



