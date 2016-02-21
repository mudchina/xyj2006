// Room: /u/dragon/kaifengadd/kf1.c

inherit ROOM;

void create()
{
	set("short", "官道");
	set("long", @LONG
        

　　一条宽阔的大道，贯穿南北，直同边关。

LONG);
  set("exits", ([
        "west" : "/d/kaifeng/tieta",
        "north" : __DIR__"guandao1",
      ]));

  set("outdoors", __DIR__);

  setup();
  
}


