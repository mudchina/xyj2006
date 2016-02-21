// Room: /d/33tian/33tian
inherit ROOM;

void create ()
{
  set ("short", "离恨天");
  set ("long", @LONG

这里就是天的尽头。抬头望去，上面是白茫茫的一片，白云从你指间
流过。你的脚下就是天宫了，隐约能看到雕栏画栋，听到丝竹笙歌，
光彩流动，奇丽不可名状。这里没有昼夜之分，只有空气中不时传来
缕缕清香，令人感到平静安宁。
LONG);

  set("light_up", 1);
  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"west1",
]));

  setup();
}
