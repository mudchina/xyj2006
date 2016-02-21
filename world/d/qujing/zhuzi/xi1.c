// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "夕林门");
  set ("long", @LONG

夕林门是城西门，城门紧避，楼上飘着一杏黄旗上书“朱紫国”三
个大字，一些校尉在门口巡查。东边方向是著名的食市夕林街，飘
来阵阵饭菜香。

LONG);

  set("exits", ([ 
    "east" : __DIR__"xi2",
  ]));
  set("objects", ([
    __DIR__"npc/xiaowei" : 2,
  ]));
  set("objects", ([
    __DIR__"npc/people" : 2,
  ]));
  set("outdoors", __DIR__"");
  setup();
}

int valid_leave(object who, string dir)
{
  if (! interactive(who) &&
      dir == "west")
    return 0;
  return ::valid_leave(who, dir);
}
