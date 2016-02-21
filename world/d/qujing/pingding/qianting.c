// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "前厅");
  set ("long", @LONG

前厅的四周是狰狞的石壁，石壁上渗出一滴滴的水珠，长着青
青的苔藓。厅的西边有一个出口，通向洞门，往东是一石门洞，
里面燃着篝火。

LONG);

  set("exits", ([
        "west"   : __DIR__"dongmen",
        "east"   : __DIR__"dating",
      ]));
  set("objects", ([
        __DIR__"npc/yao1"   : 2,
      ]));

  setup();
}



