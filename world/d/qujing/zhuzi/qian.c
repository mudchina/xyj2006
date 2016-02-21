// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "前宫");
  set ("long", @LONG

前宫为十二柱大殿，柱柱朱红绘有金龙彩凤。柱顶上挂有银铃，叮当
随风而鸣音乐声脆回韵不绝。殿顶画着紫色祥云朵朵缭绕，瑞气朦胧
彩雾千条。

LONG);
  set("exits", ([ 
    "north" : __DIR__"gongmen",
    "southwest" : __DIR__"yuhua",
    "south" : __DIR__"zheng",
  ]));
  set("objects", ([
    __DIR__"npc/taijian" : 2,
    __DIR__"npc/girl" : 2,
  ]));

  setup();
}

int valid_leave(object who, string dir)
{
  if (! interactive(who) &&
      dir == "north")
    return 0;
  return ::valid_leave(who, dir);
}
