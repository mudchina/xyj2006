#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "龙沙台");
  set ("long", @LONG

龙沙台约有一丈见方，上面有细沙铺就，整个台面非常的平整。
台的东面高悬一口铜钟，象是在水中传讯是用的。有几个小妖在
台上舞刀弄枪，比划拳脚。前方就看到水晶宫了。
LONG);

  set("objects", ([ /* sizeof() == 1*/ 
  "/d/sea/npc/soldier2" : 1,
]));
//  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"tandi1",
  "north" : __DIR__"yujie",
]));
//      
        set("water", 1);
//  
  setup();
}

