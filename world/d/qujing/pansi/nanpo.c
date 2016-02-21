// created by snowcat 11/16/1997

inherit ROOM;

void create ()
{
  set ("short", "南坡");
  set ("long", @LONG

天光斜照，南坡下野草丛生乱石奇畸，坡上雾气如蒸熏熏然然
令人头晕目眩。风吹过，声音有点凄凄惨惨。

LONG);

  set("exits", ([
        "northeast"    : __DIR__"qiaolin5",
      ]));
  set("objects", ([
        __DIR__"npc/woman"    : 1,
      ]));
  set("outdoors",__DIR__"");
  setup();
}

