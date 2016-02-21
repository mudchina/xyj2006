// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "桥北");
  set ("long", @LONG

金灯桥北十分热闹，有不少镇外的村民也来观灯。西北方是一
条小路，往南便是金灯桥头。河水从西而来自桥下潺潺流过，
向东流去。

LONG);

  set("exits", ([
        "northwest"   : __DIR__"cunlu2",
        "south"   : __DIR__"qiao",
      ]));
  set("outdoors", __DIR__);

  setup();
}



