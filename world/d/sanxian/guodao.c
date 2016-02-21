#include <room.h>
inherit ROOM;
void create()
{
        set("short", "过道");
        set("long", @LONG
一个过道。比较狭窄。
LONG
  );
  set("exits",([
        "northwest" : __DIR__"huating",
        "southeast" : __DIR__"fangbian",
      ]));  

        set("no_magic",1);
        
        create_door("southeast", "木门", "northwest", DOOR_CLOSED);
        setup();
} 
