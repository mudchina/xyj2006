// created by snowcat 11/16/1997

inherit ROOM;

void create ()
{
  set ("short", "石院");
  set ("long", @LONG

庭院深深，花草盛茂。院子由山石垒就，中间有一白霜矮松，
边上又是三五棵杂青树，藤条倒挂，周围芝兰香散万千花。西
边有一厨廊，南边有一石洞。

LONG);

  set("exits", ([
        "north"   : __DIR__"shitou",
        "south"   : __DIR__"shidong",
        "west"    : __DIR__"chulang",
      ]));
  set("objects", ([
        __DIR__"npc/girl4"    : 1,
        __DIR__"npc/girl5"    : 1,
      ]));
  set("outdoors",__DIR__"");
  setup();
}

