//Cracked by Roath
inherit NPC;

string *names = ({
  "[33mÍÃ¾«[m",
  "[34mºü¾«[m",
  "[35mâ¯¹Ö[m",
  "[36mÂ¹¾«[m",
});

void create()
{
  int i = random(sizeof(names));
  set_name(names[i], ({"yao jing"}));
  set("per",12);
  set("combat_exp", 50000);
  set("daoxing", 50000);
  set("max_force",500);
  set("force",500);
  set("max_kee",500);
  set("max_sen",500);
  set("force_factor",10);
  set("max_mana",500);
  set("mana",600);
  set_skill("unarmed",50);
  set_skill("dodge",50);
  set_skill("force",50);
  set_skill("parry",50);
  set_skill("spells",50);
  setup();
  carry_object("/d/qujing/huangfeng/obj/cloth")->wear();  
}
