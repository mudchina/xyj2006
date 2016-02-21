// created by snowcat 11/21/1997

inherit ROOM;

void create ()
{
  set ("short", "宅院");
  set ("long", @LONG

宽敞的宅院里住着几户人家，家家门口是木栅门木帘子，院子
里有几棵橙子树，上面结满了金黄色的橙子。树上牵着几根绳
子，挂着洗净的衣服。

LONG);

  set("exits", ([
        "south"    : __DIR__"zhai2",
        "west"    : __DIR__"jie4",
      ]));
  set("objects", ([
        __DIR__"obj/elong"    : 1,
      ]));
  set("outdoors",__DIR__"");
  setup();
}

