// edited by mind
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "筒子");
        set("long", @LONG
四下仍是一片黑暗，就像是站在一个筒子里，一个可以
上下活动的筒子。
LONG
  );
  set("exits",([
        "up" : __DIR__"tongzi1",
        "east" : __DIR__"didao1",
        
      ]));  
        set("no_magic",1);
        
        setup();
} 
