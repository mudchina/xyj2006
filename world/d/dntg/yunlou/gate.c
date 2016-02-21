//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "云楼宫门");
set("long", @LONG
    
云楼宫乃是托塔李天王的住宅，未近宫门已觉兵气森森。门楼上
高悬一龙吞漆金匾，上书“托塔天王府”五个大字。门旁兵将盔
明铠亮，警惕有神的护卫着府门。
LONG );


set("exits", ([
  "west"   : "/d/dntg/yaochi/wmj2",
  "east"   : __DIR__"yongdao",
]));

set("objects", ([
    __DIR__"npc/yushi" : 1,
    __DIR__"npc/yaocha" : 1,
]));

  create_door("east", "云楼宫门", "west", DOOR_CLOSED);


set("outdoors", 1);

setup();
}
