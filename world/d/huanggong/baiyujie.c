// Room: /d/huanggong/guangchang.c
inherit ROOM;

void create ()
{
  set ("short", "白玉阶");
  set ("long", @LONG

一条百余级的石阶联系于朝天场和皇宫大堂之间。玉石全是上
好的汉白玉，每块上面还雕着各种飞禽走兽，形象逼真，呼之
欲出。阶上两名金甲卫士巍然而立，警惕的盯着过往官员。
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/weishi" : 2,
]));
  set("outdoors", "/d/huanggong");
  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"dadian",
  "southdown" : __DIR__"guangchang.c",
  //"east" : __DIR__"changlang",
]));

  setup();
}
