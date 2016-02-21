// zhting.c

inherit ROOM;

void create ()
{
  set ("short", "司房");
  set ("long", @LONG

房中摆的是一排排的架子，上面分门别类的摆放着一卷卷的文
书。这里便是阴曹地府的司房，天下芸芸众生的生死都在这里
记录。偶尔几个小官出入，翻开书卷查着什么。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"roomout",
]));
  set("hell", 1);
  set("out_doors", 1);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/zhutawei" : 1,
]));

  setup();
}
