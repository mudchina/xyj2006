// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "正府");
  set ("long", @LONG

大殿里庄严肃穆，殿窗由名贵香木雕成，墙上有鹅绒绣毯，地
上铺的是虎皮地毯。殿心为一汉白玉台阶，上有一盘龙宝座，
宝座顶上有双凤彩屏。

LONG);

  set("exits", ([
        "north"   : __DIR__"dayuan",
        "southwest"   : __DIR__"ting",
      ]));
  set("objects", ([
        __DIR__"npc/dianguan"  : 2,
        __DIR__"npc/prince"  : 1,
      ]));

  setup();
}



