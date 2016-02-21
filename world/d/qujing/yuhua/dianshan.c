// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "典膳所");
  set ("long", @LONG

两扇对开雕木花门将典膳所装饰的极为讲究，让人觉得这里是
非常人能够来的地方。临街的贴花窗下放着一虎脚桌，两把宽
臂椅放在桌子两侧。

LONG);

  set("exits", ([
        "north"   : __DIR__"xiaojie8",
      ]));
  set("objects", ([
        __DIR__"npc/chaiguan"  : 1,
      ]));

  setup();
}



