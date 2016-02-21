// edited by mind

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
        "down" : __DIR__"tongzi4",
        "up" : __DIR__"shudong",
      ]));  
   set("objects", ([
      
     ]) );  
        
        setup();
} 
