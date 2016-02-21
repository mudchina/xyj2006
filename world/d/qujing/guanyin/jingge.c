inherit ROOM;

void create ()
{
  set ("short", "经阁");
  set ("long", @LONG

这里是小和尚们平时来学习的地方，屋子里面摆放了
几个大蒲团。
LONG);

  set("exits", ([
        "south" : __DIR__"langdao3",
      ])); 
        set("objects", 
        ([ //sizeof() == 3
                __DIR__"npc/guangmou" : 1,
        ]));

  setup();
}

