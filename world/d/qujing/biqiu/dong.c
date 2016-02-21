// created by snowcat 11/21/1997

inherit ROOM;

void create ()
{
  set ("short", "清华洞");
  set ("long", @LONG

一片烟霞幌亮，日月偷明。洞外云雾飞，洞里翠藓乱漫庭，一
边是滑凳攀长蔓，另一边有一小平桥挂着青藤，下有泉水潺潺
流过。石屏上有几个大字：“清华仙府”。

LONG);

  set("exits", ([
        "out"    : __DIR__"zhuang",
      ]));
  set("objects", ([
        __DIR__"npc/yao"    : 5,
      ]));
  setup();
}

