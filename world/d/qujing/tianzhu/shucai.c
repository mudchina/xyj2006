// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "蔬菜市场");
  set ("long", @LONG

蔬菜市场为一小空场地，地上堆了一些烂菜叶瓜皮之类的垃圾。
场地中有不少搭棚售菜的农妇，不时也可见到几位菜农挑着担
子来来往往。

LONG);

  set("exits", ([
        "east"   : __DIR__"jiedao75",
      ]));
  set("objects", ([
        __DIR__"npc/wei"   : 1,
      ]));

  setup();
}


