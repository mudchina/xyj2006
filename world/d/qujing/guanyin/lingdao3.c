inherit ROOM;

void create ()
{
  set ("short", "岭道");
  set ("long", @LONG

万壑争流，千崖竞秀。鸟啼人不见，花落树犹香。山草发，
野花开，悬崖峭壁，薜萝生，峻岭平岗。涧边双鹤饮，石上
野猿狂。真是个好风光。
LONG);
 
 set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/guai" : 2,
        ]));
  set("exits", ([
        "southup" : __DIR__"fangcaopo",
        "northdown"  : __DIR__"lingdao2",
      ]));

  set("outdoors", __DIR__);

  setup();
}

