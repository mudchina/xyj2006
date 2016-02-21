// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "天井");
  set ("long", @LONG

深深的天井里，几根木头搭着架子，架子上搭着一些兽皮，地
上有一些光溜溜的大石块，上面晒着肉巴子。天井的一角堆着
一些骨头。

LONG);

  set("exits", ([
        "west"    : __DIR__"bopiting",
      ]));
  set("objects", ([
        __DIR__"npc/xiaoyao" : 4,
      ]));
  set("outdoors",__DIR__"");
  setup();
}

