// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "珍楼");
  set ("long", @LONG

珍楼里摆了几张漆木桌子，桌子上放着一些青瓷盘子，盘子里
放着一些斋果。门边有几张虎皮躺椅，边上配有小茶几。珍楼
的南边有门通向大雄宝殿。

LONG);

  set("exits", ([
        "south"   : __DIR__"daxiong",
      ]));
  set("objects", ([
        __DIR__"npc/tong"   : 3,
        __DIR__"obj/zhaiguo"   : 2,
      ]));

  setup();
}



