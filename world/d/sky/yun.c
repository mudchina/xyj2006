//beitian.c
//created 4-8-97, pickle

#include <room.h>
#include <ansi.h>
inherit ROOM;


int valid_leave();

void create ()
{
  set ("short", "云海");
  set ("long", @LONG

四周是浩瀚的云海……什么也看不清。

LONG);

  set("exits", ([ /* sizeof() == 1 */
    "north" : "/d/pantao/fengb",
    "south" : __DIR__"beitian",
  ]));

  setup();
}


