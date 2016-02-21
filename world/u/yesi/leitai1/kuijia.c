// create by snowcat jan 21 1998

inherit ROOM;

void create ()
{
  set ("short", "盔甲场");
  set ("long", @LONG

御相府的盔甲场里堆积了不少各种各样的盔甲防具，几乎都是从四处
收集而来。这些盔甲防具在分类挑选之后，或是送至京城进贡，或是
转交给军务大臣处。盔甲场的北边是出口。

LONG);

  set("exits", ([
        "north" : __DIR__"zhong",
      ]));
  set("objects", ([
        __DIR__"npc/xiaotong" :  1,
        __DIR__"npc/xpo" :  1,
      ]));

  setup();
}


