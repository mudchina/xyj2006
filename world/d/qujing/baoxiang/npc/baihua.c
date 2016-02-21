// create by snowcat 10/16/1997

inherit NPC;

int execute_ask();

void create()
{
  set_name("°Ù»¨Ðß", ({"baihua xiu", "baihua" }));
  set("title","Èý¹«Ö÷");
  set("gender", "Å®ÐÔ");
  set("age", 24);
  set("attitude", "peaceful");
  set("shen_type", 1);
  set("per", 30);
  set("int", 30);
  set("max_kee", 600);
  set("max_gin", 600);
  set("max_sen", 600);
  set("force", 700);
  set("max_force", 700);
  set("force_factor", 50);
  set("max_mana", 700);
  set("mana", 700);
  set("mana_factor", 40);
  set("combat_exp", 250000);
  set("daoxing", 100000);

  set_skill("unarmed", 60);
  set_skill("dodge", 60);
  set_skill("parry", 60);
  set_skill("spells", 60);
  set_skill("force", 60);
  set("inquiry", ([
        "ÐÅ" : (: execute_ask() :),
        "¹úÍõ" : (: execute_ask() :),
        "letter" : (: execute_ask() :),
        "king" : (: execute_ask() :),
  ]));
  setup();
  carry_object("/d/qujing/baoxiang/obj/spqun")->wear();
  
}

void init()
{
  ::init();
  call_out ("check_rescure",1,this_player());
}

int execute_ask ()
{
  object who = this_player();
  object me = this_object();
  object letter = 0;

  if (who->query("combat_exp")<20000)
  {
    command ("shake");
    return 1;
  }

  if (environment(me)->query("short")!="²¨ÔÂ¶´")
  {
    command ("shake");
    return 1;
  }

  if (present("huangpao guai",environment(me)))
  {
    command ("shake");
    return 1;
  }

  if (present("shan yao",environment(me)))
  {
    command ("shake");
    return 1;
  }

  if (me->query("given"))
  {
    command ("shake");
    return 1;
  }

  if (who->query("obstacle/baoxiang")=="done")
  {
    command ("shake");
    return 1;
  }

  command ("nod");
  me->set("given",1);
  letter = new ("/d/qujing/baoxiang/obj/letter");
  letter->move(me);
  command ("whisper "+who->query("id")+" ½«´ËÃØÐÅËÙ½»¹úÍõ£¡ÊÂ²»ÒË³Ù£¡");
  command ("give "+who->query("id")+" "+letter->query("id"));
  if (! who->query("obstacle/baoxiang"))
    who->set("obstacle/baoxiang","got_letter");
  who->set_temp("obstacle/baoxiang","got_letter");
  who->save();
  return 1;
}

int check_rescure (object who)
{
  object me = this_object();
  object ling;

if (!who) return 1;
  if (present("huangpao guai",environment(me)))
  {
    return 1;
  }

  if (present("shan yao",environment(me)))
  {
    return 1;
  }


  if (who->query_temp("obstacle/baoxiang")!="given_letter")
    return 1;
  if (! ling)
 if (!objectp(ling = present("junling pai", who))) return 1;
  if (me->query("leader"))
    return 1;
  me->set("leader",who->query("id"));
  message_vision("$N¶Ô$n¼±ÇÐµØËµµÀ£º¶÷ÈË£¡¿ì´øÎÒÈ¥¼û¸¸Íõ£¡\n",me,who);
  command("follow "+who->query("id"));
  me->set_temp("no_return",1);
  return 1;
}

void kill_ob(object ob)
{
  object husband = present("huangpao guai",environment(this_object()));

  if (husband && interactive(husband))
    husband = present("huangpao guai 2",environment(this_object()));

  if (husband)
    husband->kill_ob(ob);
  ::kill_ob(ob);
}

void unconcious()
{
  ::unconcious();
  die();
}
ÿ
