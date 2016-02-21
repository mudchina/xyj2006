// create by snowcat 11/6/1997

inherit NPC;

void create()
{
  set_name("ÑýÍõ", ({"yao wang", "wang" }));
  set("title","ÈüÌ«Ëê");
  set("gender", "ÄÐÐÔ");
  set("age", 80);
  set("attitude", "peaceful");
  set("shen_type", 1);
  set("per", 30);
  set("int", 30);
  set("max_kee", 1300);
  set("max_gin", 1300);
  set("max_sen", 1300);
  set("force", 800);
  set("max_force", 800);
  set("force_factor", 90);
  set("max_mana", 800);
  set("mana", 800);
  set("mana_factor", 40);
  set("combat_exp", 960000);
  set("daoxing", 1500000);

  set_skill("unarmed", 90);
  set_skill("dodge", 90);
  set_skill("parry", 90);
  set_skill("spells", 90);
  set_skill("force", 90);
  set_skill("gouhunshu", 90);
  set_skill("tonsillit", 90);
  set_skill("ghost-steps", 90);
  set_skill("jinghun-zhang", 90);
  map_skill("unarmed", "jinghun-zhang");
  map_skill("dodge", "ghost-steps");
  map_skill("force", "tonsillit");
  map_skill("spells", "gouhunshu");
  set("eff_dx",-150000);
  set("nkgain",200);
  
  setup();
  carry_object("/d/obj/cloth/shoupiqun")->wear();
  
}

void kill_ob (object ob)
{
  set_temp("my_killer",ob);
  ::kill_ob(ob);
}

void die()
{
  object where = environment();
  object ob = query_temp("my_killer");

  if (where)
  {
    message("sound","\n\nÖ»ÌýµÃ°ë¿ÕÀ÷Éù¸ß½Ð£º¡°ÊÖÏÂÁôÇé£¬¹ÛÒôÀ´Ò²£¡¡±\n",where);
    message("sound", "\nÑýÍõ´òÁËÒ»¸ö¹ö£¬ÏÖÁË½ðÃ«ÊÞÔ­ÐÎ£¬±»Ò»µÀ½ð¹âÕÖÈ¥¡£\n\n", 
            where);
  }
  if (ob)
    ob->set_temp("obstacle/zhuzi_killed",1);

  destruct (this_object());
}

void unconcious()
{
  die();
}
ÿ