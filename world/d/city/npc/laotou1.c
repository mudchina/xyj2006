inherit NPC;

void create()
{
  string dir;
  set_name("武馆看门老头", ({"lao tou", "laotou", "lao", "tou"}) );
  set("gender", "男性" );
  set("age", 22+random(10));
  set("per", 14);
  set("long","一个武馆的看门老头。\n");

  set_temp("apply/attack", 30);
  set_temp("apply/defense", 30);
  set_skill("unarmed", 50);
  set_skill("dodge", 50);
  set_skill("parry", 50);
  set_skill("stick", 30);
  set("combat_exp", 15000);
  set("str", 25);
  set("attitude","heroism");
  setup();
  /*
  dir = __DIR__;
  dir[strlen(dir)-4] = 0;
  */
  dir = "/d/city/";
  add_money("silver", 2);
}

void init()
{
  object who;
  ::init();
  if (interactive(who = this_player()))
  {
     call_out("asking", 1, who);
  }
}

int accept_object (object who, object ob)
{
  object me;
  me = this_object();

  if ((! ob) ||
       ob->value() < 6000) 
  {
    message_vision ("$N白了你一眼：进门费少了点，我老头下半辈子怎么活啊？？？\n", me);
    return 1;
  }  
  who->set_temp("has_paid", 2);
  me->remove_all_killer();
  message_vision ("$N赶忙给你让了条路，指了指里面，说道：“快进快出喔！上头知道可不得了”。\n",me);
  return 1;
}

void asking(object who)
{
  object me;
  me = this_object();

  if (! who || environment(who) != environment())
    return;
  if (! living (me))
    return;

  if ((who && who->query_temp("has_paid") <= 0) 
	&& (string)who->query("family/family_name")!="五庄观1" )
  {
    message_vision ("$N走了过来，对$n伸手一拦，上头有通知，暂不能进!\n",me,who);
    remove_call_out ("warning1");
      call_out("warning1", 5+random(5), who);
        call_out("killing", 25+random(5), who);
  }
  else
  { 
    message_vision ("$N对$n点了点头，好吧。\n",me,who);
    me->remove_all_killer();
  }
}

void warning1(object who)
{
  object me;
  me = this_object();

  if (who &&
      environment(who) == environment(me) &&
      living(me) &&
      who->query_temp("has_paid") <= 0)
  {
    message_vision ("$N不耐烦的说道：别在这里瞎逛，快走、快走。\n",me,who);
  }
}


void killing(object who)
{
  object me;
  me = this_object();

  if (who &&
      environment(who) == environment(me) &&
      living(me) &&
      who->query_temp("has_paid") <= 0)
  {
    //me->kill_ob(who);
    //use command here...
    command("kill " + who->query("id"));
  }
}

