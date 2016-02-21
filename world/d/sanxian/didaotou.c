// edited by mind
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "地道尽头");
        set("long", @LONG
地道并不长，尽头处有一扇门，门上面也雕刻着一些人物花草，看来，单只
建这条地道，就不知花了多少人力物力，这里的主人肯花这么大的人力物力在地
下建造条走道，当真不知是个什么样的怪物。
门，并没有上锁。
LONG
  );
  set("exits",([
        "west" : __DIR__"didao1",
        "east" : __DIR__"huating",
      ]));  
   set("objects", ([
      
     ]) );  
        set("no_magic",1);
        
        create_door("east", "刻花门", "west", DOOR_CLOSED);
        setup();
} 
