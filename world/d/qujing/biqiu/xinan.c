// created by snowcat 11/21/1997

inherit ROOM;

void create ()
{
  set ("short", "溪南");
  set ("long", @LONG

南岸是一片杨树林，清溪在林外徐徐流着，不时可见溪上飘着
青树枝和碎花瓣。风吹过，杨树叶哗啦作响。

LONG);

  set("exits", ([
        "north"    : __DIR__"xibei",
        "southwest"    : __DIR__"zhuang",
      ]));
  set("outdoors",__DIR__"");
  setup();
}

int valid_leave (object who, string dir)
{
  if (dir == "north")
    message_vision ("$N一脚踏进溪流，慢慢走了过去。\n",who);
  return 1;
}
