//Cracked by Roath
// create by snowcat jan 21 1998

inherit ROOM;

void create ()
{
  set ("short", "静心宫");
  set ("long", @LONG

静心宫瑞气朦胧，墙角放着几乌铁架，上面有瓷盆芝兰花草香蕙之类
的植物。宫顶上悬挂着大小铜钟，纹丝不动。北边墙上正中写着一个
金色大字“静”。

LONG);

  set("exits", ([
        "west" : __DIR__"ningxin",
      ]));
  set("no_fight", 1);
  set("no_magic", 1);
  setup();
}

void init ()
{
  add_action ("do_jing","jing");
}

int do_jing ()
{
  object who = this_player();
//  int i = (60 - who->query_kar())*3;
  int i = (45 - random(who->query_kar()))*2
          -who->query_temp("kaifeng_donate_silver");

  if (i<2) i=2;

  if (who->is_busy())
    return notify_fail("你的动作还没有完成，不能动。\n");

  message_vision ("$N缓缓地道出一个“静”字，俯首盘腿坐下。\n",who);
  who->start_busy (i,i);

  call_out ("finishing",i,who);
  return 1;
}

void finishing (object who)
{
  who->interrupt_me();
  who->set_temp("kaifeng_jingxin",1);
  message_vision ("$N深深地吐出一口气，徐徐站了起来。\n",who);
}

