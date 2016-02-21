// created by snowcat on 4/12/1997

inherit NPC;

string *names = ({
  "ºüÀê¾«",
  "Ò°¼¦¾«",
  "Ïã÷ê¾«",
  "»¨â¯¾«",
  "²Êµû¾«",
});

void create()
{
  int i = random(4)+1;
  string str;
  set_name(names[random(sizeof(names))], ({"yao jing", "yao", "jing"}));
  set("gender", "Å®ÐÔ");
  set("age", 18);
  set("combat_exp", 30000*i);
  set("per", 10);
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
  carry_object("/d/obj/cloth/shoupiqun")->wear();
  carry_object("/d/qujing/qilin/obj/shield")->wear();
  str = "/d/qujing/qilin/obj/weapon20";
  str[strlen(str)-1] = '0'+random(3);
  carry_object(str)->wield();
}
ÿ