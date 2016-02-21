// created by snowcat 11/16/1997

inherit ROOM;

void create ()
{
  set ("short", "木香亭");
  set ("long", @LONG

木香亭八角玲珑，花草环绕。风吹铜铃丁当声脆。亭边有一小
溪缓缓流过，清清雅雅。亭子的东面是茅草屋，往南可见一石
头门洞。

LONG);

  set("exits", ([
        "east"    : __DIR__"maowu",
        "south"   : __DIR__"shitou",
      ]));
  set("objects", ([
        __DIR__"npc/girl2"    : 1,
        __DIR__"npc/girl3"    : 1,
      ]));
  set("outdoors",__DIR__"");
  setup();
}

