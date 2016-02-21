// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "民居");
  set ("long", @LONG

这家人家也是陈姓，屋子里放着大小陶盆瓷罐，里面种着花草
之类的东西。南边的两扇窗子大开，从外面飘来一股花草的清
香味。

LONG);

  set("exits", ([
        "out"   : __DIR__"chen3",
      ]));
  set("objects", ([
        __DIR__"npc/people"  : random(1)+1,
        __DIR__"npc/kid"  : random(1)+1,
      ]));

  setup();
}



