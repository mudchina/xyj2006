// created by snowcat 11/21/1997

inherit ROOM;

void create ()
{
  set ("short", "彩铺");
  set ("long", @LONG

彩铺里放着各类花草盆景，陈列在货架上，兼卖灯笼彩纸笔墨
之类的杂物。。这里的手工制作的花篮花瓶很有名气，曾被比
丘国王列为贡品。

LONG);

  set("exits", ([
        "north"    : __DIR__"jie3",
      ]));
  set("objects", ([
        __DIR__"npc/binumuyi"    : 1,
      ]));
  setup();
}

