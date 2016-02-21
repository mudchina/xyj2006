// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "后宫");
  set ("long", @LONG

后宫装饰艳丽，粉墙上摆着一排排的凤尾屏扇。朝北有一排玉
格窗，挂着珍珠帘。南宫墙下放着雾纹桌和云晕椅。桌上的梳
妆台散发着迷人的香味。

LONG);

  set("exits", ([
        "east"   : __DIR__"hou4",
        "west"   : __DIR__"hou2",
        "south"   : __DIR__"yuhua",
      ]));
  set("objects", ([
        __DIR__"npc/girl"   : 2,
        __DIR__"npc/fakegirl"   : 1,
      ]));

  setup();
}


