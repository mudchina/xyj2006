inherit ROOM;

void create ()
{
  set ("short", "菜园");
  set ("long", @LONG

和尚们平时吃的菜大都是从这里出来的，所以
这里是平时最热闹的地方，现在还有
几个小和尚在给青菜浇水呢。
LONG);

 set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/seng" : 2,
        ]));
  set("exits", ([
          "west" : __DIR__"langdao3",
      ])); 

     setup();
}

