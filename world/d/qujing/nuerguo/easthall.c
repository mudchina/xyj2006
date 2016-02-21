// created by snowcat.c 4/4/1997
// room: /d/nuerguo/easthall.c

inherit ROOM;

void create ()
{
  set ("short", "东侧殿");
  set ("long", @LONG

这里是西梁王宫的东侧殿。一架大屏风将殿分成两半，屏风
后放着一些大大小小的漆红嵌金箱子彩盒，看样子给西梁公
主送礼进贡的人的确不少。

LONG);

  set("exits", ([
        "west"  : __DIR__"fronthall",
      ]));

  setup();
}






