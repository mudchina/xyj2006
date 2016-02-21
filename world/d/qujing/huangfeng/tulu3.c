// created by wxb 12/24/1998
// room: /d/qujing/huangfeng/tulu3.c

inherit ROOM;

void create ()
{
  set ("short", "乡间土路");
  set ("long", @LONG

村子建于群山之间，一条溪流绕村而过。路上有三三两两的
行人走过，都是些补实的村中之人。北边一座高山拔地而起，
直耸云霄。山上流泉飞瀑，鸟兽齐鸣，这山就是黄风岭了。

LONG);

  set("exits", ([
        "east" : __DIR__"tulu2",
        "south" : __DIR__"tulu4",
	 "northup" : __DIR__"huangfeng",
       ]));
  set("objects", ([
                __DIR__"npc/people": 1 ]) );

  set("outdoors", __DIR__);

  setup();
}