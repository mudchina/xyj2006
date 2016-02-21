//Cracked by Roath
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.3
//  /d/qujing/shuangcha/shanlu5.c

inherit ROOM;

void create ()
{
  set ("short", "村前");
  set ("long", @LONG

村庄前是几颗参天古木，树叶折射出幽黑的颜色，仿佛两个门卫
守护着村庄，还有一些野藤盘旋在上面，一座白板桥横跨村前，
虽然这没有多少水。
LONG);

  set("exits", ([
        "eastup" : __DIR__"shanlu5",
        "west"   : __DIR__"gate",
        "southwest" : "/d/qujing/yingjian/xiaolu1",
      ]));
  set("outdoors","sc");
  setup();
}
