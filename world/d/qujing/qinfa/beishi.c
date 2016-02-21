// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "北市");
  set ("long", @LONG

这里市容整洁，路面翻修一新，由六角石镶嵌而铺就。四周种
着果子树，散发着淡香气。往南是更为热闹的中市，往北是乾
坤场。

LONG);

  set("exits", ([
        "north"    : __DIR__"qiankun",
        "south"    : __DIR__"zhongshi",
      ]));
  set("outdoors",__DIR__"");
  setup();
}

