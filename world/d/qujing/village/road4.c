//Cracked by Roath
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.7
//  /d/qujing/village/road1.c

inherit ROOM;

void create ()
{
  set ("short", "村内小路");
  set ("long", @LONG

木桥的倒影印在了水中，显得各位的美丽，村庄全部都是粉
泥墙壁，很显眼，转也砌的比较围圜，一个个高堂壮丽，大
厦甚得清安。

LONG);
  set("exits", ([
        "northwest" : "/d/qujing/sanda/shanlu2",
         "enter": __DIR__"house",
        "southeast"  : __DIR__"cunkou",
          ]));
  set("outdoors","cz");
  setup();
}
