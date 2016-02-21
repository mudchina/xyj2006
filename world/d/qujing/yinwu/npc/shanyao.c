// created by snowcat on 12/5/1997

inherit NPC;

void create()
{
  set_name("É½Ñı", ({"shan yao","yao"}));
  set("gender", "ÄĞĞÔ");
  set("age", 40);
  set("long","Ò»¸öĞ×Ïà±ÏÂ¶µÄÉ½Ñı¡£\n");
  set("attitude", "aggressive");
  set("combat_exp", 500000);
  set("daoxing", 400000);
  
  set("no_nk_reward",1);

  set("per", 15);
  set_skill("parry", 80);
  set_skill("unarmed", 80);
  set_skill("dodge", 80);
  set_skill("blade", 80);
  set_skill("fork", 80);
  set_skill("mace", 80);
  set_skill("spear", 80);
  set_skill("sword", 80);
  set_skill("whip", 80);
  set_skill("axe", 80);
  set_skill("hammer", 80);
  set_skill("rake", 80);
  set_skill("stick", 80);
  set_skill("staff", 80);
  set_skill("dagger", 80);
  set("max_sen",400);
  set("max_gee",400);
  set("max_gin",400);
  set("force",400);
  set("max_force",400);
  set("max_mana",400);
  set("force_factor",3);
  setup();
  carry_object("/d/qujing/yinwu/obj/cloth")->wear();
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

  message_vision ("\n$Nµ¹ÁËÏÂÈ¥£¬»¯ÎªÒ»¶ÑÊŞ¹Ç¡£\n",me);  
  if (! present("shan yao 3",where) &&
      where->query("short")=="Â·¿Ú")
  {
    object ob = new ("/d/qujing/yinwu/npc/shanyao");
    ob->move(where);
    message_vision ("\nÍ»È»£¬É½ÑÒÉÏÓÖ±ÄÏÂÀ´Ò»¸ößÚÑÀßÖ×ìµÄÉ½Ñı£¡\n",me);   
  }
  destruct (me);  
}

void unconcious ()
{
  die();
}
ÿ
