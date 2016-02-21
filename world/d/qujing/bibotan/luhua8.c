#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "芦花荡");
  set ("long", @LONG

走如芦花荡便如走入一个迷宫，前后左右都是一人多高的芦
草，密密麻麻的让人辩不清方位，随风而舞的芦花沾了人满
身都是。
LONG);

//  set("objects", ([ /* sizeof() == 1*/ 
//  __DIR__"npc/erlang" : 1,
//]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"luhua5",
  "east" : __DIR__"luhua2",
  "north" : __DIR__"luhua9",
  "south" : __DIR__"luhua7",
]));

  setup();
}

