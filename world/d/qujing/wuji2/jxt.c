// Room: /u/mimi/zhuziguo/jinxiangting.c  snowcat moved to /d/qujing/wuji
inherit ROOM;

void create ()
{
  set ("short", "锦香亭");
  set ("long", @LONG

亭畔种着一簇牡丹，红艳欲滴。牡丹原产东土洛阳，乌鸡国王知道
皇后爱花，而牡丹又为花中之王，是以不惜代价差人移植到此，真
可谓名花倾国两相欢，常得君王带笑看了。

LONG);

  set("outdoors", __DIR__"");                   
  set("exits", ([ /* sizeof() == 3 */
    "west" : __DIR__"hzm.c",
    "north" : __DIR__"qiyutan.c",
    "east" : __DIR__"huilang.c",
  ]));
  set("objects", ([
      __DIR__"npc/queen" : 1,
      __DIR__"npc/girl" : 3,
  ]));

  setup();
}

