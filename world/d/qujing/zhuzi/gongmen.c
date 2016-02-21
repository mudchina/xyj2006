// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "宫门");
  set ("long", @LONG

一座金壁辉煌的大门，门上有一对朱龙紫凤盘绕。门前左右各有一只
玉石精雕麒麟栩栩如生。这便是朱紫国的皇宫大门朝北是朱紫街，东
西是护宫河。

LONG);
  set("exits", ([ 
    "west" : __DIR__"hugong1",
    "east" : __DIR__"hugong2",
    "north" : __DIR__"zhuzi5",
    "south" : __DIR__"qian",
  ]));
  set("objects", ([
    __DIR__"npc/xiaowei" : 4,
  ]));
  set("outdoors", __DIR__"");
  setup();
}

int valid_leave(object who, string dir)
{
  if (! interactive(who) &&
      dir == "south")
    return 0;
  return ::valid_leave(who, dir);
}
