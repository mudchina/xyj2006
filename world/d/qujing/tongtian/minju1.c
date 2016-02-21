// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "民居");
  set ("long", @LONG

这是一户陈姓人家，屋子里摆设简单，设有一木桌两木椅，里
面是一张床，上面的被褥叠得整整齐齐。北面有一个木窗子，
窗外传来鸡叫。

LONG);

  set("exits", ([
        "out"   : __DIR__"chen1",
      ]));
  set("objects", ([
        __DIR__"npc/people"  : random(2),
        __DIR__"npc/kid"  : random(2),
      ]));

  setup();
}



