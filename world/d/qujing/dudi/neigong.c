// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "内宫");
  set ("long", @LONG

内宫是一方洞，洞里铺满了软花草，宫北的石墙上挂着彩色凤
尾帘，墙下放着一香木梳妆台，台上有银面镜。内宫的西面有
一出口通往花亭子。

LONG);

  set("exits", ([
        "west"   : __DIR__"huating",
      ]));
  set("objects", ([
        __DIR__"npc/yao"   : 4,
      ]));

  setup();
}



