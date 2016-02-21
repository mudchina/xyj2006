// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/hougong2.c

inherit ROOM;

void create ()
{
  set ("short", "后宫");
  set ("long", @LONG

后宫里四面宝镜高悬，宫殿的地面由赤铜一字铺开，华贵之极。
宫内供着仙果仙花，案上的宝烛辉煌，馥郁真香，真是令人心
旷神怡。

LONG);

  set("exits", ([
        "west"         : __DIR__"hougong1",
        "east"         : __DIR__"hougong3",
        "south"        : __DIR__"jinluan",
      ]));

  set("objects",([
          __DIR__"npc/girl"     : 3,
      ]));
  setup();
}

