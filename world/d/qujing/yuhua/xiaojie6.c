// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "小街");
  set ("long", @LONG

一条由碎石夯实的小街。小街有丈许宽，两边走着一些行人，
街上不时有马车驶过。小街的南面是一座砖瓦楼，上书：“审
理厅”三个大字。

LONG);

  set("exits", ([
        "west"   : __DIR__"xiaojie5",
        "south"   : __DIR__"shenli",
        "east"   : __DIR__"xiaojie7",
      ]));
  set("outdoors", __DIR__);

  setup();
}



