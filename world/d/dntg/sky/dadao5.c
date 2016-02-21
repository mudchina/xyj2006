// Room: /d/sky/nantianmen
 
#include <room.h>
#include <ansi.h>
inherit ROOM;

void init();
void close_gate();
int do_knock(string);
int valid_leave();
string look_gate();

void create ()
{
  set ("short", "天宫大道");
  set ("long", @LONG

一条大道，笔直的伸展出去，直通南天门。道上不时走过几名
巡查的天兵，持刀悬剑，威风凛凛。

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"dadao6",
  "south" : __DIR__"dadao4",

]));


   set("outdoors", 1);


  setup();
}
 
