// rewritten by snowcat on 4/11/1997
// room: dongkou

inherit ROOM;

void create ()
{
  set ("short", "芭蕉洞口");
  set ("long", @LONG

你一抬头，见已经来到一个巨大的洞口，洞的形状犹如一个怪兽的
大嘴。洞门紧闭牢关，洞外风光秀丽。

LONG);

  set("exits", ([
        "west" : __DIR__"cuiyun1",
        "east" : __DIR__"shimen",
      ]));
  set("outdoors", "firemount");

  setup();
}
