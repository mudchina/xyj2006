// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "南市");
  set ("long", @LONG

南市是一片住宅区和客店，整个街道被高高低低的石墙土墙围
住，有开满花的蔓藤爬满了四面的墙。往南远远望去可见街道
上挂满了灯笼招牌，往北可以看见中市。

LONG);

  set("exits", ([
        "north"    : __DIR__"zhongshi",
        "south"    : __DIR__"jiedao8",
      ]));
  set("outdoors",__DIR__"");
  setup();
}

