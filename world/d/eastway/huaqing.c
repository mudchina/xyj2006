// create by snowcat.c 4/20/1997
// room: /d/eastway/huaqing.c

inherit ROOM;

void create ()
{
  set ("short", "曲江池");
  set ("long", @LONG

这里已到了城边，听人讲这里有一个神秘的温泉，泉水清澈，雾
气缭绕，为修补成仙的极佳场所。因此有许多人纷纷远道而来，
求得一浴。
LONG);

  set("exits", ([
        "enter"         : __DIR__"xianquan",
        "northwest"     : __DIR__"guandao3",
      ]));
  set("objects", ([
        __DIR__"npc/luren"     : 2,
      ]));
  set("outdoors", __DIR__);

  setup();
}






