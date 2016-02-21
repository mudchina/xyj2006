// by snowcat 12/8/1997

inherit NPC;

void create()
{
  set_name("Ð¡Íõ×Ó", ({"xiao wangzi", "wangzi", "wang", "zi"}));
  set("title", "Óñ»ªÏØ");
  set("gender", "ÄÐÐÔ");
  set("age", 15);
  set("per", 25);
  set("attitude", "peaceful");
  set("shen_type", 1);
  set("combat_exp", 100000);
  set("daoxing", 50000);

  set_skill("unarmed", 40);
  set_skill("dodge", 40);
  set_skill("parry", 40);
  set_skill("staff", 70);
  set("max_gin",400);
  set("max_kee",400);
  set("max_sen",400);
  set("max_force",400);
  set("max_mana",400);
  set("force_factor",30);
  set("eff_dx",8000);
  set("nkgain",30);
  setup();
  carry_object("/d/obj/cloth/mangpao")->wear();
}

int accept_object (object who, object ob)
{
  object me = this_object();
  string id = "xiao xiangyao zhang";

  if (ob->query("id") != id)
  {
    message_vision ("$N¶Ô$nÒ¡Í·ËµµÀ£º²»Òª²»Òª¡£\n",me,who);
    call_out ("return_ob",1,ob,who);
    return 1;
  }
  if (who->query("combat_exp") < 10000)
  {
    message_vision ("$NÒ¡Í·ËµµÀ£º$nµÀÐÐ²»¹»Ò²£¬ÕâÍæÒâÅÂÊÇÓÐ¼Ù¡£\n",me,who);
    call_out ("return_ob",1,ob,who);
    return 1;
  }
  if (present(id,me))
  {
    message_vision ("$N¶Ô$nÒ¡Í·ËµµÀ£ºÎÒÒÑÓÐÁË£¬ÄúÄÇ»òÐíÊÇ¼Ù»õÒ²¡£\n",me,who);
    call_out ("return_ob",1,ob,who);
    return 1;
  }
  message_vision ("$NÊ§Éù½ÐµÀ£º"+ob->query("name")+"¾ÃÑ°²»µÃÒ²¡£\n",me,who);
  message_vision ("$NËµµÀ£º¶àÐ»¶àÐ»£¡\n",me);
  who->set_temp("obstacle/yuhua_zhang",1);
  call_out ("wield_me",1,ob);
  return 1;
}

void return_ob (object ob, object who)
{
  if (ob)
    command ("give "+ob->query("id")+" to "+who->query("id"));
}

void wield_me (object ob)
{
  if (ob)
    command ("wield "+ob->query("id"));
}
ÿ