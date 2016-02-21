// by snowcat on 11/5/1997 
inherit NPC;

void create()
{
  set_name("É½¼§", ({ "shan ji", "ji" }) );
  set("gender", "Å®ÐÔ");
  set("combat_exp", 10000);
  set("daoxing", 250000);

  set("long","Ò»Î»½¿ÑÞÃÔÈËµÄÒ°Å®×Ó¡£\n");
  set("age", 20);
  set("per", 20);
  set("attitude", "friendly");
  set("combat_exp", 500000);
  set("daoxing", 250000);

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
  if (where->query("short")!="É½Â·")
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
  if(sizeof(filter_array(all_inventory(environment(this_object())), (:userp:))))
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
  message_vision ("\n$NÉí×ÓÒ»ÈíÏÖÁËÔ­ÐÎ£¬¾¹ÊÇÒ»Ö»Ä¸É½¼¦£¬ÆË´ò×Å³á°ò¡£\n",me);
  ji->move(environment(me));
  destruct (me);
}

void unconcious()
{
  die();
}
ÿ