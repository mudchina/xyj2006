// Room: /u/mimi/zhuziguo/princehouse.c
inherit ROOM;

void create ()
{
  set ("short", "太子府");
  set ("long", @LONG

此处乃是太子的行宫。三年前，国王认为太子已经成人，故为其另
造宫殿，习文练武，没有诏令，不得私自进宫，以免分心。

LONG);

  set("exits", ([ /* sizeof() == 3 */
    "west" : __DIR__"nstreet2",
    "northeast" : __DIR__"shufang.c",
    "east" : __DIR__"garden.c",
  ]));
  set("objects", ([
    __DIR__"npc/siwei" : 2,
  ]));

  setup();
}

int valid_leave (object who, string dir)
{
  if (dir != "west" && !interactive(who))
    return 0;
  return ::valid_leave(who, dir);
}
