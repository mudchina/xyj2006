// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "乌林子");
  set ("long", @LONG

黑压压远远一片林子，树木茂密，杂草有齐胸高。乱石丛中有
一条弯曲的小路，路上碎石高高低低地铺开。风吹草动，仿佛
四周有眼睛在暗处盯着你。

LONG);

  set("exits", ([
        "northwest"   : __DIR__"wulin1",
        "southwest"   : __DIR__"shan14",
      ]));
  set("outdoors", __DIR__);

  setup();
}



