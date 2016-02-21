// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "街口");
  set ("long", @LONG

这里北霞街与朱紫街交叉，路口繁华，人来人往不断。往北可以远
远看见朱紫门，往南通向朱紫国的城中心鼓楼，东西两边各自通向
北霞街。

LONG);

  set("exits", ([ 
    "north" : __DIR__"zhuzi2",
    "south" : __DIR__"zhuzi3",
    "west" : __DIR__"beixia3",
    "east" : __DIR__"beixia4",
  ]));
  set("outdoors", __DIR__"");
  setup();
}
