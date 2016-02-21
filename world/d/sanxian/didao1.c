// edited by mind
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "地道");
        set("long", @LONG
两旁是雕刻精致的石壁，壁上嵌着发亮的铜灯。
LONG
  );
  set("exits",([
        "west" : __DIR__"tongzi4",
        "east" : __DIR__"didaotou",
      ]));  
        set("no_magic",1);
        
        setup();
} 
