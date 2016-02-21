// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "五鼓楼");
  set ("long", @LONG

五鼓楼上彩带飞舞，楼下人群熙熙攘攘。日出日落击鼓，星月
满天时分则敲梆报夜安。东西两边是街道，南北两端则各有一
些铺子。

LONG);

  set("exits", ([
        "west"    : __DIR__"jiedao5",
        "east"    : __DIR__"jiedao6",
        "north"    : __DIR__"zahuopu",
        "south"    : __DIR__"mipu",
      ]));
  set("outdoors",__DIR__"");
  setup();
}

