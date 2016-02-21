inherit ROOM;

void create ()
{
  set ("short", "休息室");
  set ("long", @LONG

靠墙的地方有一排一排的床，这里就是和尚们休
息的地方。
LONG);

 set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/seng" : 1,
        ]));
  set("exits", ([
         "down" : __DIR__"langdao3",
      ])); 

  setup();
}

