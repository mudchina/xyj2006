//Cracked by Roath
// created by snowcat on 12/9/1997

inherit NPC;

string *names = ({
  "Ââ¹Ö",
  "¶¿¹Ö",
  "âµ¹Ö",
  "ºü¹Ö",
  "Öí¹Ö",
  "â¯¹Ö",
  "Ñò¹Ö",
  "Â¹¹Ö",
  "»¢¹Ö",
  "ÃÓ¹Ö",
  "ÐÜ¹Ö",
  "Å£¹Ö",
  "ÀÇ¹Ö",
  "±·¹Ö",
});

void create()
{
  int i = random(9)+1;
  string str;
  set_name(names[random(sizeof(names))], ({"yao guai", "yao", "guai"}));
  set("gender", "ÄÐÐÔ");
  set("age", 20);
  set("combat_exp", 20000*i);
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
  set("max_sen",200*i);
  set("max_gee",200*i);
  set("max_gin",200*i);
  set("force",200*i);
  set("max_force",200*i);
  set("max_mana",200*i);
  set("force_factor",10*i);
  setup();
  carry_object("/d/obj/cloth/shoupiqun")->wear();
  carry_object("/d/qujing/jilei/obj/armor")->wear();
  str = "/d/qujing/jilei/obj/weapon0";
  str[strlen(str)-1] = '0'+random(7);
  carry_object(str)->wield();
}


ÿ