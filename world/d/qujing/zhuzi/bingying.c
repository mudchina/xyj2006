// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "兵营");
  set ("long", @LONG

这里是一个大院，驻扎着皇家的兵将。兵营门口有旌旗飘扬，几位校
尉来来回回地走动，一些士兵在集队呐喊着操练。院子西南角有一兵
器架。


LONG);
  set("exits", ([ 
    "west" : __DIR__"zhuzi5",
  ]));
  set("objects", ([
    __DIR__"npc/xiaowei" : 3,
  ]));
  set("outdoors", __DIR__"");
  setup();
}
