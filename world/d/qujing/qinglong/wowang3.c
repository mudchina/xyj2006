// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "卧王室");
  set ("long", @LONG

王室门口放着一白铜大鼎，鼎里散发着酥香油的醇香味。室内
有一金边红纹木案，上面点着三盏酥香油灯，将屋子照得一片
通亮。

LONG);

  set("exits", ([
        "northwest"   : __DIR__"tongdao2",
      ]));
  set("objects", ([
        __DIR__"npc/pi3"  : 1,
      ]));

  setup();
}



