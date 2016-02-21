// created by snowcat on 4/9/1997
// madao.c

inherit NPC;

void create()
{
  string dir;
  set_name("马盗", ({"ma dao", "madao", "ma", "dao"}) );
  set("gender", "男性" );
  set("age", 22+random(10));
  set("per", 14);
  set("long","一个蛮横凶狠的马盗，专门袭击过路马车。\n");

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
  dir = "/d/westway/";
  carry_object(dir+"obj/mabang")->wield();
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
       ob->value() < 200) 
  {
    message_vision ("$N一瞪眼：就这点东西？不想活了？？？\n", me);
    return 1;
  }  
  who->set_temp("has_paid", 2);
  me->remove_all_killer();
  message_vision ("$N嘿嘿嘿几声怪笑，闪身让道。\n",me);
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
	&& (string)who->query("family/family_name")!="五庄观" )
  {
    message_vision ("$N冲过来，对$n大喝一声：要钱还是要命？\n",me,who);
    remove_call_out ("warning1");
    remove_call_out ("warning2");
    remove_call_out ("warning3");
    call_out("warning1", 5+random(5), who);
    call_out("warning2", 10+random(5), who);
    call_out("warning3", 15+random(5), who);
    call_out("killing", 25+random(5), who);
  }
  else
  { 
    message_vision ("$N对$n一拱手，闪身让道。\n",me,who);
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
    message_vision ("$N大声喝道：快给钱！\n",me,who);
  }
}

void warning2(object who)
{
  object me;
  me = this_object();

  if (who &&
      environment(who) == environment(me) &&
      living(me) &&
      who->query_temp("has_paid") <= 0)
  {
    message_vision ("$N又喊叫几声：拿钱来买命！\n",me,who);
  }
}

void warning3(object who)
{
  object me;
  me = this_object();

  if (who &&
      environment(who) == environment(me) &&
      living(me) &&
      who->query_temp("has_paid") <= 0)
  {
    message_vision ("$N急了：你到底给不给钱？\n",me,who);
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

