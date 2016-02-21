// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "天阳门");
  set ("long", @LONG

这里是朱紫国城门的东门，门上飘着杏黄旗上书“朱紫国”。城门
宽敞，西面是天阳街，东北是通向城郊山坡的路。门口有些校尉在
盘查行人。

LONG);

  set("exits", ([ 
    "northeast" : "/d/qujing/qilin/polu1",
    "west" : __DIR__"tian3",
  ]));
  set("objects", ([
    __DIR__"npc/xiaowei" : 2,
  ]));
  set("outdoors", __DIR__"");
  setup();
}

int valid_leave(object who, string dir)
{
  if (! interactive(who) &&
     dir == "northeast")
    return 0;
  return ::valid_leave(who, dir);
}
