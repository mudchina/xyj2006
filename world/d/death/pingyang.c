inherit ROOM;

void create ()
{
  set ("short", "平阳大路");
  set ("long", @LONG

这里是一条笔直的大路，南方看起来已是一片光亮，那里便是
阴阳相交的贵道门。北面却是阴云笼罩，传来阵阵悲歌的枉死
城，咫尺相隔，却有天涯之别。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"guidaomen",
  "north" : __DIR__"bidouya",
]));
  set("hell", 1);

  setup();
}
