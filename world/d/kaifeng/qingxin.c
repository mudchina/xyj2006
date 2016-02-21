//Cracked by Roath
// create by snowcat jan 21 1998

inherit ROOM;

void create ()
{
  set ("short", "清心宫");
  set ("long", @LONG

清心宫里摆着各种奇花异果，散发着迷人的水果清香。地上铺着褚红
色的地毯。北边墙上挂着许多小明亮的铜镜，墙的正中写着一个金色
大字“清”。

LONG);

  set("exits", ([
        "east" : __DIR__"ningxin",
      ]));
  set("no_fight", 1);
  set("no_magic", 1);
  setup();
}

void init ()
{
  add_action ("do_qing","qing");
}

int do_qing ()
{
  object who = this_player();
//  int i = (60 - who->query_kar())*3;
  int i = (45 - random(who->query_kar()))*2
          -who->query_temp("kaifeng_donate_silver");

  if (i<2) i=2;

  if (who->is_busy())
    return notify_fail("你的动作还没有完成，不能动。\n");

  message_vision ("$N缓缓地道出一个“清”字，俯首盘腿坐下。\n",who);
  who->start_busy (i,i);

  call_out ("finishing",i,who);
  return 1;
}

void finishing (object who)
{
  who->interrupt_me();
  who->set_temp("kaifeng_qingxin",1);
  message_vision ("$N深深地吐出一口气，徐徐站了起来。\n",who);
}

