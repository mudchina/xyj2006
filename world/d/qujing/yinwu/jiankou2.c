// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "涧口");
  set ("long", @LONG

山石高耸之处，有斜坡自两岸缓缓而下，底下是潺潺流水之声
不断，涧水冲击着流水中的大小石块，发出一阵阵震耳欲聋的
轰鸣浪声，近处有几条暗沟。

LONG);

  set("exits", ([
        "southwest"    : __DIR__"huangye1",
      ]));
  set("objects", ([
        __DIR__"npc/shanyao" : 3,
      ]));
  set("outdoors",__DIR__"");
  setup();
}

