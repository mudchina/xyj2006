// created by snowcat on 12/5/1997

inherit NPC;

void create()
{
  int i = random(9)+1;
  set_name("ÊØÃÅÅ£¾«", ({"shoumen niujing", "niujing", "jing"}));
  set("gender", "ÄÐÐÔ");
  set("age", 20*i);
  set("long","Ò»¸öÊØÎÀÄÚ¹¬µÄÑý¾«¡£\n");
  set("combat_exp", 20000*i);
  set("per", 15);
  set_skill("parry", 20*i);
  set_skill("unarmed", 20*i);
  set_skill("dodge", 20*i);
  set("max_sen",200*i);
  set("max_gee",200*i);
  set("max_gin",200*i);
  set("force",200*i);
  set("max_force",200*i);
  set("max_mana",200*i);
  set("force_factor",20*i);
  setup();
  carry_object("/d/obj/cloth/shoupiqun")->wear();
}

void die ()
{
  object me = this_object();
  object where = environment (me);
  object bone = present ("bone 4",where);

  if (! bone)
  {
    bone = new ("/d/obj/misc/bone");
    bone->move(where);
  }

  message_vision ("\n$Nµ¹ÁËÏÂÈ¥£¬»¯ÎªÒ»¶ÑÊÞ¹Ç¡£\n",me);  
  if (! present("shoumen niujing 4",where))
  {
    object ob = new ("/d/qujing/qinglong/npc/xiniu");
    ob->move(where);
    message_vision ("\n´ÓÀïÃæÓÖ´Ú³öÒ»Î»$N£¡\n",me);   
  }
  destruct (me);  
}

void unconcious ()
{
  die();
}

void return_ob (object ob, object who)
{
  if (ob)
    command ("give "+ob->query("id")+" to "+who->query("id"));
}

void destruct_me (object ob)
{
  destruct (ob);
}

int accept_object (object who, object ob)
{
  object me = this_object();

  if (ob->query("name") != "ÓÍºùÂ«")
  {
    message_vision ("$NÒ¡ÁËÒ»ÏÂÍ·£¬ËµµÀ£º²»Òª¡£\n",me);
    call_out ("return_ob",1,ob,who);
    return 1;
  }
  if (ob->query("liquid/remaining") == 0)
  {
    message_vision ("$NÒ¡ÁËÒ»ÏÂÍ·£¬ËµµÀ£ºÓÍºùÂ«ÊÇ¿ÕµÄ¡£\n",me);
    call_out ("return_ob",1,ob,who);
    return 1;
  }
  message_vision ("$NËµµÀ£ºÐ»Ð»£¡\n",me);
  who->set_temp("obstacle/jinping_give_hulu",1);
  call_out ("destruct_me",1,ob);
  return 1;
}
ÿ