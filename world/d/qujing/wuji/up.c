// Room: /city/erlou.c  snowcat moved to /d/qujing/wuji

inherit ROOM;

void create()
{
set("short", "二楼客房");
set("long", @LONG

客房里整齐大方，四周放着床铺和雕木小几。临街是一排窗子，挂
着薄窗帘，是个歇脚休息的好地方。

LONG);

  set("sleep_room",1);
  set("if_bed",1);

  set("exits", ([
    "down" : __DIR__"kezhan",
  ]));

  setup();
}

int valid_leave(object me, string dir)
{
  me->delete_temp("rent_paid");
  return ::valid_leave(me, dir);
}
