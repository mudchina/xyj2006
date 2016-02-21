// created by snowcat on 4/12/1997

inherit NPC;

void create()
{
  string str;
  set_name("Ð¡Ñý", ({"xiao yao","yao"}));
  set("gender", "ÄÐÐÔ");
  set("age", 20);
  set("long","Ò»¸öÐ×Ïà±ÏÂ¶µÄÐ¡Ñý¡£\n");
  set("attitude", "aggressive");
  set("combat_exp", 150000);
  set("daoxing", 100000);

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
  set("force_factor",10);
  setup();
  carry_object("/d/obj/cloth/shoupiqun")->wear();
  carry_object("/d/qujing/pingding/obj/armor")->wear();
  str = "/d/qujing/pingding/obj/weapon10";
  str[strlen(str)-1] = '0'+random(2);
  carry_object(str)->wield();
}
ÿ