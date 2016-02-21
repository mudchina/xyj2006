// by snowcat

inherit NPC;

void create()
{
  set_name("ÎºÕ÷", ({ "wei zheng", "wei", "zheng" }));
  set("title", "Ø©Ïà");
  set("gender", "ÄÐÐÔ");
  set("age", 60);
  set("per", 30);
  set("combat_exp", 300000);
  set("daoxing", 800000);

  set_skill("force", 80);
  set_skill("spells", 80);
  set_skill("unarmed", 80);
  set_skill("dodge", 80);
  set_skill("parry", 80);
  set("gin", 3000);
  set("max_gin", 3000);
  set("kee", 3000);
  set("max_kee", 3000);
  set("sen", 3000);
  set("max_sen", 3000);
  set("force", 1000);
  set("max_force", 1000);
  set("mana", 1000);
  set("max_mana", 1000);
  set("force_factor", 80);
  setup();
  carry_object("/d/obj/cloth/jinpao")->wear();
  carry_object("/d/kaifeng/obj/sijuan")->wear();
}

void init ()
{
  object me = this_object();
  object who = this_player();

  if (! wizardp(who) &&
      interactive(who))
  {
    object where = environment(me);
    
    if (! where->valid_player(who))
      message_vision ("$N¶Ô$nËµµÀ£ºÕâÀïÊÇÈü³¡£¬"+RANK_D->query_respect(who)+
                      "²»¿ÉËæ±ãÂÒ´³Ò²¡£\n",me,who);
    else 
      command ("hi "+who->query("id")); 
    if (who->query("env/wimpy") > 0)
    {
      who->set("env/wimpy",0);
      message_vision ("$N¶Ô$nËµµÀ£ºÔÚÕâÀïÉ±Éí²»ÉË½î¹Ç£¬ÀÏ·òÌæÄã½«ÌÓÃüÏµÊý(wimpy)ÖÃÁãÁË¡£\n",me,who);

    }
  }
}

void die ()
{
  object me = this_object();

  message_vision ("\nµØÏÂ´«À´´ÞÅÐ¹ÙµÄÉùÒô£º$NÑôÊÙÎ´¾¡£¡\n",me);
  message_vision ("\n$N²üÎ¡Î¡µØ´ÓµØÉÏË¦ÐäÅÀ½«ÆðÀ´¡£\n",me);
  set("kee", 3000);
  set("sen", 3000);
}

void unconcious()
{
  die();
}

void accept_fight (object ob)
{
  object me = this_object();

  message_vision ("$NÁ¬Ã¦Ìø¿ªËµ£ºÀÏ·ò½î¹ÇÒÑÐà£¬²»´ò£¬²»´òÒ²£¡\n",me);
}

void kill_ob (object ob)
{
  object me = this_object();

  message_vision ("$NÁ¬Ã¦Ìø¿ªËµ£ºÀÏ·ò½î¹ÇÒÑÐà£¬²»´ò£¬²»´òÒ²£¡\n",me);
  me->remove_all_killer();
  all_inventory(environment(me))->remove_killer(me);
}
ÿ