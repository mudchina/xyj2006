// zhting.c

inherit ROOM;

void create ()
{
  set ("short", "司房");
  set ("long", @LONG

房内光线暗淡，外面的浓雾还不时地从半开着的门缝飘进来。地面
上散着一些破旧的物品，不过光从外表已经无法分辨出那是些什么
东西了。
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"new-yinsi2",
]));
  set("hell", 1);

  setup();
}


