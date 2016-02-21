// Room: /d/33tian/west1
inherit ROOM;

void create ()
{
  set ("short", "离恨天");
  set ("long", @LONG

四处白茫茫一片，你似乎飘在白云之上。东边，南边，和北边都看不
远。只有西边，隐隐现出一座宫殿。殿门上横挂着一面闪闪发光的金
匾，上写着「兜……」。
LONG);

  set("light_up", 1);
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"doushuai-gate",
  "east" : __DIR__"33tian",
]));

  setup();
}
