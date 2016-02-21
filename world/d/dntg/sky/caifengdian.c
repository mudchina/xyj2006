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
  set ("short", "彩凤殿");
  set ("long", @LONG

外厢犹可，入内惊人：里壁厢有几条彩羽凌空丹顶凤。明霞幌幌
映天光，碧雾蒙蒙遮斗口。

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"jieyindian",
]));

  setup();
}
 
