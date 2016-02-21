// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "米铺");
  set ("long", @LONG

店里面一字排开放着米袋，米袋打开，露出白色的大米和面粉。
柜台上有一石磨，供磨香料之类的作料。几只陶罐里放着油盐
酱菜。

LONG);

  set("exits", ([
        "north"    : __DIR__"wugu",
      ]));
  set("objects", ([
        __DIR__"npc/chen"    : 1,
      ]));
  setup();
}

