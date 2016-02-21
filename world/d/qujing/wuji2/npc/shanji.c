// by snowcat on 11/5/1997 
inherit NPC;

void create()
{
  set_name("山姬", ({ "shan ji", "ji" }) );
  set("gender", "女性");
  set("combat_exp", 10000);
  set("long","一位娇艳迷人的野女子。\n");
  set("age", 20);
  set("per", 20);
  set("attitude", "friendly");
  set("combat_exp", 500000);
  set_skill("unarmed", 100);
  set_skill("dodge", 100);
  set_skill("parry", 100);
  set_skill("force", 100);
  set_skill("spells", 100);
  set("force_factor", 50);
  set("max_gin", 750);
  set("max_kee", 750);
  set("max_sen", 750);
  set("max_force", 700);
  set("max_mana", 800);

  setup();
  carry_object("/d/obj/cloth/skirt")->wear();
}

void init ()
{
  object me = this_object();
  object who = this_player();
  object where = environment(me);

  remove_call_out ("emoting");
  call_out ("emoting",random(9)+1,me,who);
  if (! interactive(who))
    return;
  if (where->query("short")!="山路")
  {
    me->set_leader(0);
    return;
  }
  if (me->query("has_followed"))
    return;
  me->set("has_followed",1);
  me->command_function("giggle "+who->query("id"));
  me->command_function("follow "+who->query("id"));
  me->set_leader(who);
}

void emoting (object me, object who)
{
  if (! who)
    return;
  if (environment(who) != environment(me))
    return;
  if (me->is_fighting())
    return;
  remove_call_out ("emoting");
  call_out ("emoting",random(60)+20,me,who);
  switch (random(3))
  {
    case 0 : 
    {
      me->command_function("giggle "+who->query("id"));
      break;
    }
    case 1 : 
    {
      me->command_function("giggle "+me->query("id"));
      break;
    }
    case 0 : 
    {
      me->command_function("giggle");
      break;
    }
  }
}

void die ()
{
  object me = this_object();
  object ji = new (__DIR__"ji");
  message_vision ("\n$N身子一软现了原形，竟是一只母山鸡，扑打着翅膀。\n",me);
  ji->move(environment(me));
  destruct (me);
}

void unconcious()
{
  die();
}

