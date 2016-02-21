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
  set ("short", "接引殿");
  set ("long", @LONG

进了南天门，已经可以看到一座座天宫放着七彩霞光，忽隐忽现
于云遮雾绕之中。里壁厢有几根大柱，柱上缠绕着金鳞耀日赤须
龙；一座白玉桥弯弯曲曲地向北延伸，东西两边各有一座大殿，
也不知是干什么用的，你可以隐约听到东边殿中有喧哗之声，似
乎人不少。

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"nantian",
  "north" : __DIR__"caihongqiao",
  "west" : __DIR__"caifengdian",
  "east" : __DIR__"jinlongdian",
]));

  create_door("south", "南天门", "north", DOOR_CLOSED);
        set("no_clean_up", 0);

  setup();
}
 
