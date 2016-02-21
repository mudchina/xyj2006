// Room: /d/jjf/main_cabinet.c

inherit ROOM;

void create ()
{
  set ("short", "无私轩");
  set ("long", @LONG
秦将军是个孝子，对自己的母亲照顾的无微不至。无私轩里面
布置虽然朴素，但显然处处都曾费过一番心思。迎门的一幅山水画
更是不俗，定是名家手笔。
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"stone_road2",
  "west" : __DIR__"bingqi_room",
  "east" : __DIR__"main_shufang",
]));

  setup();
}
