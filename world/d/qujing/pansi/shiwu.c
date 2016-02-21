// created by snowcat 11/16/1997

inherit ROOM;

void create ()
{
  set ("short", "石屋");
  set ("long", @LONG

落花中座立一玲珑石屋，屋边修竹翠绿枝枝秀，屋后红梅叶叶
舒。石檐上紫花朵朵盛开，有鸟雀莺燕鸣唱。石屋一边是花涧
缓流，另一面是碧溪潺潺。

LONG);

  set("exits", ([
        "west"    : __DIR__"huajian1",
        "northeast"    : __DIR__"bixi1",
        "southeast"    : __DIR__"bixi4",
        "enter"    : __DIR__"wunei",
      ]));
  set("outdoors",__DIR__"");
  setup();
}

