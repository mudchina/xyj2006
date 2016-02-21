// Room: /d/jjf/majuan.c

inherit ROOM;

void create ()
{
  set ("short", "马厩");
  set ("long", @LONG
秦将军一生曾有过两匹战马。黄骠马在先，后又从尚师徒手中
得到呼雷豹。秦将军南征北战若是缺了坐下宝马，早尸横沙场了。
因此他对自己的两匹战马有特殊的感情。马厩修的舒适异常，而且
还有专人照顾。
LONG);

  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/xiaotong" : 1,
  __DIR__"npc/huangbiao" : 1,
  __DIR__"npc/hulei" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"front_yard",
]));
  set("out_doors", 1);

  setup();
}
