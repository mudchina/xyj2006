// created by snowcat 11/21/1997

inherit ROOM;

void create ()
{
  set ("short", "大殿");
  set ("long", @LONG

大殿里龙柱凤檐富丽堂皇，南边是鹅黄落地绒，上面用珍珠绣
有青松逗红梅，北面是一排白玉窗，窗檐上雕着白鹤飞仙图。
往西有铺花道通往宝殿。

LONG);

  set("exits", ([
        "east"    : __DIR__"zhaomen",
        "west"    : __DIR__"bao",
      ]));
  set("objects", ([
        __DIR__"npc/taijian"    : 1,
      ]));
  setup();
}

