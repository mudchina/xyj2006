// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "石廊");
  set ("long", @LONG

洞在这里略显狭窄，左右都是粗糙的石壁，有滴水缓缓流下，
落在地上发出叮咚的声音。东北方有光线从洞外斜照进来，南
边仍然有另一个石壁。

LONG);

  set("exits", ([
        "northwest"   : __DIR__"shimen",
        "south"   : __DIR__"shilang2",
      ]));
  set("objects", ([
        __DIR__"npc/yao2"   : 3,
      ]));

  setup();
}



