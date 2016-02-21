// created by snowcat on 4/12/1997

inherit NPC;

void create()
{
  int i = random(9)+1;
  set_name("É½Ñý", ({"shan yao","yao"}));
  set("gender", "ÄÐÐÔ");
  set("age", 20*i);
  set("long","Ò»¸öÐ×Ïà±ÏÂ¶µÄÉ½Ñý¡£\n");
  set("combat_exp", 20000*i);
  set("per", 15);
  set_skill("parry", 10*i);
  set_skill("unarmed", 10*i);
  set_skill("dodge", 10*i);
  set_skill("blade", 10*i);
  set_skill("fork", 10*i);
  set_skill("mace", 10*i);
  set_skill("spear", 10*i);
  set_skill("sword", 10*i);
  set_skill("whip", 10*i);
  set_skill("axe", 10*i);
  set_skill("hammer", 10*i);
  set_skill("rake", 10*i);
  set_skill("stick", 10*i);
  set_skill("staff", 10*i);
  set_skill("dagger", 10*i);
  set("max_sen",100*i);
  set("max_gee",100*i);
  set("max_gin",100*i);
  set("force",100*i);
  set("max_force",100*i);
  set("max_mana",100*i);
  set("force_factor",10*i);
  setup();
  carry_object("/d/qujing/baoxiang/obj/spqun")->wear();
}
ÿ