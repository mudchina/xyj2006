// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "大厅");
  set ("long", @LONG

大厅为洞里最大的地方，靠近洞口光线明亮。洞壁四周上长有
一层层的青苔，靠洞口的地方长着无数鲜花仙草。大厅的西边
有一走廊，东南边是洞口。

LONG);

  set("exits", ([
        "west"   : __DIR__"zou",
        "southeast"   : __DIR__"shimen",
      ]));
  set("objects", ([
        __DIR__"npc/yao"  : 2,
      ]));

  setup();
}



