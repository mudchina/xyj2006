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
        "eastdown"    : __DIR__"jiandi",
        "westup"    : __DIR__"ling2",
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

  if (who->query("combat_exp") < 5000 ||
      ! present("huang qian",who))
  {
    message_vision ("$N鼓足勇气纵身一跃，却如断线风筝一般落了下去。\n",who);
    who->move(__DIR__"jiandi");
    who->unconcious();    
    return 1;
  }
  message_vision ("$N胆颤心惊地掂脚一跳，嗖地一声跃了过去。\n",who);
  who->move(__DIR__"jiankou2");
  return 1;
}
