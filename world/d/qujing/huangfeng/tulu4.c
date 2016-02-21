// created by wxb 12/24/1998
// room: /d/qujing/huangfeng/tulu4.c

inherit ROOM;

void create ()
{
  set ("short", "乡间土路");
  set ("long", @LONG

村子建于群山之间，一条溪流绕村而过。路上有三三两两的
行人走过，都是些补实的村中之人。西边是村中的武器店。
多数行人到这里会买一些武器防身。

LONG);

  set("exits", ([
        "west"      : __DIR__"wuqidian",
        "north"   : __DIR__"tulu3",
        "south" :__DIR__"minju2",
      ]));
  set("objects", ([
                __DIR__"npc/people": 1 ]) );

  set("outdoors", __DIR__);

  setup();
}
