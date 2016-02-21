// created by wxb 12/24/1998
// room: /d/qujing/huangfeng/yangchanglu2.c

inherit ROOM;

void create ()
{
  set ("short", "羊肠小道");
  set ("long", @LONG

小路崎岖难行，只在林间蜿蜒，似乎永无尽头。一路上但见古
木参天，香花烂漫。路上没什么行人，连鸟兽也不见一只。你
不觉得加快了步子。

LONG);

  set("exits", ([
        "northwest" : __DIR__"yangchanglu1",
        "northeast" : __DIR__"yangchanglu3",
      ]));
        set("outdoors", __DIR__);
       
  setup();
}
