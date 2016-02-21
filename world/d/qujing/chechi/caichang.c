// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/caichang.c

inherit ROOM;

void create ()
{
  set ("short", "西城菜场");
  set ("long", @LONG

菜场是车迟国平民购买日常瓜果蔬菜肉类的地方。西边是满地一
片瓜皮菜叶，东边有一地的碎骨鸡毛。不远处，有几辆破旧的空
大车停在路边。

LONG);

  set("exits", ([
        "north"        : __DIR__"jieshi2",
        "east"         : __DIR__"jieshi4",
        "west"         : __DIR__"jiuguan",
        "south"        : __DIR__"taiping",
      ]));

  set("outdoors","/d/qujing/chechi");
  setup();
}

