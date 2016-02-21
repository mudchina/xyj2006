// created by snowcat on 12/9/1997

inherit NPC;

string *names = ({
  "ºûµû¾«",
  "Ï¸Ñü·ä¾«",
  "ÂéÎÃ¾«",
  "»¨½ã¾«",
  "²ÊÖë¾«",
});

void create()
{
  int i = random(4)+1;
  set_name(names[random(sizeof(names))], ({"yao jing", "jing", "jing"}));
  set("gender", "Å®ÐÔ");
  set("age", 20);
  set("combat_exp", 50000*i);
  set("per", 10);
  set_skill("parry", 20*i);
  set_skill("unarmed", 20*i);
  set_skill("dodge", 40*i);
  set_skill("blade", 20*i);
  set_skill("fork", 20*i);
  set_skill("mace", 20*i);
  set_skill("spear", 20*i);
  set_skill("sword", 20*i);
  set_skill("whip", 20*i);
  set_skill("axe", 20*i);
  set_skill("hammer", 20*i);
  set_skill("rake", 20*i);
  set_skill("stick", 20*i);
  set_skill("staff", 20*i);
  set_skill("dagger", 20*i);
  set("max_sen",200*i);
  set("max_gee",200*i);
  set("max_gin",200*i);
  set("force",200*i);
  set("max_force",200*i);
  set("max_mana",200*i);
  set("force_factor",10*i);
  setup();
  carry_object("/d/qujing/dudi/obj/cloth")->wear();
  carry_object("/d/qujing/dudi/obj/fork")->wield();
}

ÿ