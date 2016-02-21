// created by snowcat.c 11/16/1997

inherit ROOM;

void create ()
{
  set ("short", "涧口");
  set ("long", @LONG

山岩上一道细瀑蜿蜒而下，流作一溪山涧在脚下碎石中铺开，
向东边绕道涧底流去。东边向上是一平台，对面是另一座高山，
风景格外秀丽，却是咫尺天涯。

LONG);

  set("exits", ([
        "east"    : __DIR__"shandao4",
      ]));
  set("outdoors",__DIR__"");
  setup();
}

void init ()
{
  add_action ("do_jump","jump");
}

int do_jump ()
{
  object who = this_player();

  message_vision ("$N闭上眼睛一跳，嗖地一声跃了过去。\n",who);
  who->move(__DIR__"jiankou1");
  return 1;
}
