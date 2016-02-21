// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "卧房");
  set ("long", @LONG

一个石卧房，地上铺着各种兽皮，石壁上也挂满了兽皮兽头兽
角。靠墙边是一张黛色石桌，一张大木椅。东北方向有一石门
通往内殿。

LONG);

  set("exits", ([
        "northeast"   : __DIR__"neidian",
      ]));
  set("objects", ([
        __DIR__"npc/yao2"   : 2,
        __DIR__"npc/huaqi"   : 1,
        __DIR__"obj/shoupi"   : 2,
      ]));

  setup();
}


