// created by snowcat.c 10/14/1997
// room: /d/qujing/baoxiang/zuofang.c

inherit ROOM;

void create ()
{
  set ("short", "锡器铺");
  set ("long", @LONG

锡器铺里挂着各式各样的器皿，有长嘴锡壶，大小锡碗锡盘锡盆。
上面都打印着奇形怪状的花纹。可以听见屋后的一些小学徒正在乒
乒乓乓地敲打着锡器。

LONG);

  set("exits", ([
        "south"       : __DIR__"xi4",
      ]));
  set("objects", ([ 
    __DIR__"npc/xijiang" : 1,
  ]));
  setup();
}

