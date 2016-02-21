// Room: /d/qujing/wudidong/inner-tang.c

inherit ROOM;

void create ()
{
  set ("short", "大殿");
  set ("long", @LONG

大殿里无数小妖来回奔走，正在准备大开筵席。一个女子正中高坐，
云髻低垂，金钗半溜，正笑吟吟地指挥着众小妖，全不顾自己香汗淋
漓。你往人群中一混，一时倒也无人发觉。
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/yushu" : 1,
]));
  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"tang-gate",
]));

  setup();
}
