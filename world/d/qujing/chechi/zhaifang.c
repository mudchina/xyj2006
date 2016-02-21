// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/zhaifang.c

inherit ROOM;

void create ()
{
  set ("short", "斋房");
  set ("long", @LONG

斋房里砌了一大泥灶，上面支着一口大铁锅，灶边是两个水桶和
一些干柴。木台上放着一些粗瓷碗，还有几只木凳。南边有一门
通向院子。

LONG);

  set("exits", ([
        "south"         : __DIR__"beiyuan",
      ]));

  set("objects", ([
         __DIR__"obj/rice"    : 1,
         __DIR__"obj/kang"    : 1,
      ]));
  setup();
}

