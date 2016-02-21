// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "内宫");
  set ("long", @LONG

内宫庄严肃穆，由檀香木屏将四周隔开，屏上雕有紫金龙戏珠。宫
中间是珍珠紫龙床，上有十八床绸缎凤凰绒被，配有四对织锦鸳鸯
软心枕。

LONG);
  set("exits", ([ 
    "west" : __DIR__"neiyuan",
    "southwest" : __DIR__"housan",
  ]));
  set("objects", ([
    __DIR__"npc/king" : 1,
  ]));
  setup();
}
