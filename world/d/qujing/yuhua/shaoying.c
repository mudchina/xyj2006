// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "哨营");
  set ("long", @LONG

一座临街而建的营房，离门楼有几步之遥。此乃是护城兵士所
居之处，偶尔可见兵士进出换岗。里面有一大通铺，门口有一
空空的兵器架。

LONG);

  set("exits", ([
        "west"   : __DIR__"xiaojie1",
      ]));
  set("objects", ([
        __DIR__"npc/bing"  : 3,
      ]));

  setup();
}



