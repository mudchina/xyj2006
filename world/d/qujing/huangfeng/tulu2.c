// created by wxb 12/24/1998
// room: /d/qujing/huangfeng/tulu2.c

inherit ROOM;

void create ()
{
  set ("short", "乡间土路");
  set ("long", @LONG

村子很小，只三三两两几所民宅，街上的店铺也不多，路南
是一家药店，冷冷清清的，好像没什么生意。

LONG);

  set("exits", ([
        "east"      : __DIR__"tulu1",
        "west" : __DIR__"tulu3",
        "south"   : __DIR__"yaopu",
        "north"  : __DIR__"minju1",
      ]));
  set("objects", ([
                __DIR__"npc/people": 1 ]) );

  set("outdoors", __DIR__);

  setup();
}
