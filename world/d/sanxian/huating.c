#include <room.h>
inherit ROOM;
void create()
{
        set("short", "花厅");
        set("long", @LONG
厅堂的中央，有张桌子，桌子上有只天青色的大碗，那始终引诱着人的香气
，便是自碗里发出来的。碗里，果然是只烧得红红的鸡。四面的椅子上，都是空
荡荡的，见不到一个人影。
LONG
  );
  set("exits",([
        "west" : __DIR__"didaotou",
        "southeast" : __DIR__"guodao",
        "north" : __DIR__"sleep",
      ]));  
   set("objects", ([
      
      
      __DIR__"zhongshan":1,
     ]) );  
        set("no_magic",1);
        
        create_door("west", "刻花门", "east", DOOR_CLOSED);

        setup();
} 
