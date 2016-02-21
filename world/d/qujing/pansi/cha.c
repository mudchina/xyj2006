// created by snowcat 11/16/1997

inherit ROOM;

void create ()
{
  set ("short", "茶房");
  set ("long", @LONG

茶房宽绰光线明亮。一大茶桌靠墙而放，上面放有一些茶壶茶
盏茶盘茶果之类的茶具茶点。一双扇门通向西面的殿堂，东北
有一偏门通向厨房，南边有一客房。

LONG);

  set("exits", ([
        "west"    : __DIR__"zheng",
        "northeast"    : __DIR__"chu",
        "south"    : __DIR__"ke",
      ]));
  set("objects", ([
        __DIR__"obj/tea"    : 2,
        __DIR__"npc/xiaotong"    : 1,
      ]));
  setup();
}

