// created 11/20/1997 by snowcat

inherit NPC;

void create()
{
  set_name("°à", ({"ban"}));
  set("title", "³æ¹Ö");
  set("gender", "ÄÐÐÔ");
  set("age", 12);
  set("per", 9);
  set("long", "Ò»Ö»³æÄ£³æÑùµÄÑý¹Ö£¬³¤ÓÐ¶þ³ßÎåÁù´ç£¬ÖØÔ¼°Ë¾Å½ï¡£\n");
  set("attitude", "aggressive");
  set("max_kee", 300);
  set("max_gin", 300);
  set("max_sen", 300);
  set("force", 300);
  set("max_force", 300);
  set("mana", 300);
  set("max_mana", 300);
  set("combat_exp", 35000);
  set("daoxing", 40000);

  set("force_factor", 18);
  set_skill("unarmed", 40);
  set_skill("dodge", 150);
  set_skill("parry", 150);
  setup();
  carry_object("/d/obj/cloth/shoupi")->wear();
}

void kill_ob (object ob)
{
  set_temp("my_killer",ob);
  ::kill_ob(ob);
}

void die ()
{
  object me = this_object();
  object ob = query_temp("my_killer");
  message_vision ("\n$N±ä³ÉÒ»Ö»Ð¡³æ¶ùàÓàÓµØ·É×ßÁË¡£\n",this_object());
  if (ob && 
      ! ob->query_temp("obstacle/pansi_killed_"+me->query("name")))
  {
    ob->set_temp("obstacle/pansi_killed_"+me->query("name"),1);
    ob->add_temp("obstacle/pansi_killed",1);
  }
  destruct (me);
}

void unconcious ()
{
  die ();
}
ÿ