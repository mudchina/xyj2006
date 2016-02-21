// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "外宫");
  set ("long", @LONG

外宫里摆设整齐，这里本是接待客人的地方。宫里摆着四方石
桌以及石茶几，两边几把太师椅上垫着兽皮相对而放。宫里点
几盏兽油灯。

LONG);

  set("exits", ([
        "northwest"   : __DIR__"zhong",
        "east"   : __DIR__"guo",
      ]));
  set("objects", ([
        __DIR__"npc/yao"  : 2,
      ]));

  setup();
}



