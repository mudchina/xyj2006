// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "小吃店");
  set ("long", @LONG

店堂里干干净净，放着许多长凳长桌，来小吃店的人都是附近
的邻居街坊，一边吃着什么，一边聊天闲谈。店家是位大嫂，
正在擦着桌子。

LONG);

  set("exits", ([
        "north"   : __DIR__"jiedao91",
      ]));
  set("objects", ([
        __DIR__"npc/fu"   : 1,
      ]));

  setup();
}


