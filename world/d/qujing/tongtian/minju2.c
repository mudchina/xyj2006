// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "民居");
  set ("long", @LONG

此户人家也是陈姓，堂屋里光线明亮，摆设颇为讲究，堂心有
一八仙桌，上面放着净亮的铜茶具，屋边有几把宽背椅，中间
有一小茶几。

LONG);

  set("exits", ([
        "out"   : __DIR__"chen2",
      ]));
  set("objects", ([
        __DIR__"npc/people"  : random(2),
        __DIR__"npc/kid"  : random(2),
      ]));

  setup();
}



