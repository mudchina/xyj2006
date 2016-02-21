// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "山冈");
  set ("long", @LONG

高高的山冈上，山路顺着山势起伏，道路凸凹不平铺着大大小
小的石头块。路边怪石林立形状不可言逾，山路时宽时窄，路
边长着长长的荒草。

LONG);

  set("exits", ([
        "northwest"   : __DIR__"dalu2",
        "south"   : __DIR__"jiming",
      ]));
  set("outdoors", __DIR__);

  setup();
}



