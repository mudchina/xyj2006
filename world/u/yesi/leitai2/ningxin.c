// create by snowcat jan 21 1998

inherit ROOM;

void create ()
{
  set ("short", "宁心宫");
  set ("long", @LONG

宁心宫里烟雾缭绕，宫前有一小香桌，上面燃着麝香，烟火的香气扑
鼻。北边墙上正中写着一个金色大字“宁”。地上放着几个白底绣花
蒲团。

LONG);

  set("exits", ([
        "south" : __DIR__"sanxin",
        "west" : __DIR__"qingxin",
        "east" : __DIR__"jingxin",
      ]));
  set("no_fight", 1);
  set("no_magic", 1);
  setup();
}

void init ()
{
  add_action ("do_ning","ning");
}

int do_ning ()
{
  object who = this_player();
  int i = (45 - who->query_kar())*3
          -who->query_temp("kaifeng_donate_silver");

  if (i<10) i=10;// minumum delay time.

  if (who->is_busy())
    return notify_fail("你的动作还没有完成，不能动。\n");

  message_vision ("$N缓缓地道出一个“宁”字，俯首盘腿坐下。\n",who);
  who->start_busy (i,i);

  call_out ("finishing",i,who);
  return 1;
}

void finishing (object who)
{
  who->interrupt_me();
  who->set_temp("kaifeng_ningxin",1);
  message_vision ("$N深深地吐出一口气，徐徐站了起来。\n",who);
}

