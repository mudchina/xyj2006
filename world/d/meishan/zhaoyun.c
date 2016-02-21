
#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "朝云岭");
  set ("long", @LONG

岭上怪石嶙峋，颇为难走。石头颜色多彩，远望有如朝云，得
名于此。向山下望，江水有如一道白练，缓向东去，岸上山云
涌起，嫩绿一片。
LONG);

  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/yao" : 1,
  __DIR__"npc/li" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"sengquan",
  "northwest" : __DIR__"jixian",
]));

  setup();
}


