// created by snowcat 11/21/1997

inherit ROOM;

void create ()
{
  set ("short", "溪北");
  set ("long", @LONG

树林外一股清溪在长坡下徐徐流着，溪上飘着无数青枝花瓣。
岸边上有无数柳树轻舒长枝，随风而舞。

LONG);

  set("exits", ([
        "north"    : __DIR__"liu4",
        "south"    : __DIR__"xinan",
      ]));
  set("outdoors",__DIR__"");
  setup();
}

int valid_leave (object who, string dir)
{
  if (dir == "south")
    message_vision ("$N一脚踏进溪流，慢慢走了过去。\n",who);
  return 1;
}
