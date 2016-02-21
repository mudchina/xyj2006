// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "朱紫门");
  set ("long", @LONG

城门高耸，城头上飘着一杏黄旗，上书“朱紫国”。城门外有一护
城河，架设有一双车对行木悬桥，由粗铁链吊紧。门洞宽大，分里
中外三层门。

LONG);

  set("exits", ([ 
    "north" : __DIR__"dalu2",
    "south" : __DIR__"zhuzi2",
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
      dir == "north")
    return 0;
  return ::valid_leave(who, dir);
}
