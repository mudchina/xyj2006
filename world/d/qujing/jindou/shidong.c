// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "石洞");
  set ("long", @LONG

一个巨大的石洞出现在眼前，石洞上有“金兜山”几个大字。
洞里烟雾缭绕，有一股股妖气从洞里漫出。石洞的东北面是一
开阔地带，南边通向里洞。

LONG);

  set("exits", ([
        "northeast"   : __DIR__"shanshi2",
        "south"   : __DIR__"dongnei1",
      ]));
  set("objects", ([
        __DIR__"npc/yao"   : 2,
      ]));

  setup();
}



