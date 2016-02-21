//Cracked by Roath

inherit ROOM;

void create ()
{
  set ("short", "草屋");
  set ("long", @LONG

这是一间普通的民居，几张桌子，几张凳子都破旧不堪，里间隐隐
约约的可以看到一些模样，你想，大概是卧室吧。

LONG);

  set("exits", ([
        "north"  : __DIR__"sleeproom",

      ]));

  set("objects",([
        __DIR__"npc/lingji1.c":1,
      ]));
  	
	  set("light_up", 1);

  setup();
}
