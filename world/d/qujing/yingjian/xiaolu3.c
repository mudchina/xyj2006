//Cracked by Roath
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.3
//  /d/qujing/yingjian/xiaolu3.c

inherit ROOM;

void create ()
{
  set ("short", "山路");
  set ("long", @LONG

巍巍山峰，险要峻岭与天涯相接，不时可以看到远处一两间
茅草屋如花朵一般点缀着山川，一路上遍地是花香。一路上
处处闻鸟语。
LONG);

  set("exits", ([
        "west" : __DIR__"xiaolu4",
        "east" : __DIR__"xiaolu2",
      ]));
  set("outdoors","yj");
  setup();

}
