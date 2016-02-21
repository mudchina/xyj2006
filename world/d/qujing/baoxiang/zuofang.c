// created by snowcat.c 10/14/1997
// room: /d/qujing/baoxiang/zuofang.c

inherit ROOM;

void create ()
{
  set ("short", "小作坊");
  set ("long", @LONG

作坊的墙上挂满各式各样手工制品和织毯，一位中年男人脚踩木织
机织着毯子。屋角堆满木头块和一些未完工的家俱。透过门帘，可
以听见里间有人正在吱呀呀地纺线。

LONG);

  set("exits", ([
        "west"       : __DIR__"bei3",
      ]));

  set("objects", ([ 
    __DIR__"npc/fangzhu" : 1,
  ]));
  setup();
}

