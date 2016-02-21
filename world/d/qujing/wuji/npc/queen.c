
inherit NPC;

void create()
{
  set_name("Íõºó", ({"wang hou", "hou", "queen"}));
  set ("long", "ÎÚ¼¦¹úµÄÍõºó£¬ÖÕÈÕ³îÃ¼¿àÁ³£¬ÐÄË¼ÖØÖØ¡£\n");
  set("title", "ÎÚ¼¦¹ú");
  set("gender", "Å®ÐÔ");
  set("age", 40);
  set("combat_exp", 100000);
  set("daoxing", 50000);

  set_skill("blade", 20);
  set_skill("dodge", 20);
  set_skill("parry", 20);
  set_skill("unarmed", 20);
  set_skill("force", 20);
  set("max_sen", 500);
  set("max_kee", 500);
  set("max_force", 500);
  set("force", 100);
  set("force_factor", 4);
  setup();
 
  carry_object("/d/obj/cloth/gongpao")->wear();
}

int accept_object (object who, object ob)
{
  object me = this_object();

  if (ob->query("id") != "yu gui")
    return 0;

  remove_call_out ("telling");
  call_out ("telling",1,me,who,ob);
  message_vision ("$N¿´¼û$nÒ»Õú£¬¶ÙÊ±Á³É«°µÏÂÀ´¡£\n",me,ob);
  command ("shake");
  who->set_temp("obstacle/wuji_queen",1);
  return 1;
}

void telling (object me, object who, object ob)
{
  object yugui = present ("yu gui",me);
  
  if (! yugui)
  {
    yugui = new ("/d/qujing/wuji/obj/jade");       
    yugui->move(me);
  }
  message_vision ("Íõºó¶Ô$NËµ£º»¹ÊÇÈ¥¼ûÌ«×Ó°Õ¡£\n",who);
  me->command_function("sigh");
  me->command_function("give "+who->query("id")+" yu gui");
}

ÿ